#pragma once

#include <unistd.h>
#include <iostream>

template <typename T, typename F>
void iter(T *array, size_t size, F function){
  size_t i;
  for (i = 0; i < size; i++)
    function(array[i]);
}


template <typename T>
void print(const T& any){
  std::cout << any << std::endl;
}

template <typename T>
void incr(T& any){
  ++any;
}
