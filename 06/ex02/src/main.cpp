#include "../include/Base.hpp"
#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"

#include <ctime>
#include <exception>
#include <iostream>
#include <time.h>
#include <cstdlib>

Base* generate(void){
  int r = rand() % 3;

  if (r == 0) return (new A);
  if (r == 1) return (new B);
  if (r == 2) return (new C);
  return 0;
 }

void identify(Base* p){
  if (dynamic_cast<A*>(p))
    std::cout << "A"<< std::endl;
  if (dynamic_cast<B*>(p))
    std::cout << "B" << std::endl;
  if (dynamic_cast<C*>(p))
    std::cout << "C" << std::endl;

}

void identify(Base& p){
  try {
   (void) dynamic_cast<A&>(p);
   std::cout << "A" << std::endl;
  } catch (std::exception) {}

 try {
   (void) dynamic_cast<B&>(p);
   std::cout << "B" << std::endl;
  } catch (std::exception) {}

 try {
   (void) dynamic_cast<C&>(p);
   std::cout << "C" << std::endl;
  } catch (std::exception) {}
}

int main(){
  std::srand(time(0));
  Base* test;
  test = generate();

  identify(test);
  identify(*test);

  return 0;
}
