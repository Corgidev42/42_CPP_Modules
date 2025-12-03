#include "../include/easyfind.hpp"
#include <vector>
#include <iostream>

int main(){

  std::vector<int> list;
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);
  list.push_back(2);
  list.push_back(4);
  std::vector<int>::iterator it;
  it = easyfind(list, 2);
  std::cout << *it << std::endl;
  return 0;
}
