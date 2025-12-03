#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main(){
  struct Data* data = new Data;
  data->message = "test";
  data->value = 1;

  std::cout << data << std::endl;
  uintptr_t p = Serializer::serialize(data);
  std::cout << p << std::endl;
  data = Serializer::deserialize(p);
  std::cout << data << std::endl;
  std::cout << data->value << " et " << data->message << std::endl;
  data->message = "jfspijsifjs";
  data->value = 1239389123;
  std::cout << data << std::endl;


  return 0;
}
