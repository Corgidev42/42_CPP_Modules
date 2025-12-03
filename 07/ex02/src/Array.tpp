#include "../include/Array.hpp"
#include <stdexcept>

template<typename T>
Array<T>::Array() : _array(new T[NULL]), _size(0){}

template<typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n){}

template<typename T>
Array<T>::Array(const Array& other) : _array(new T[other._size]), _size(other._size){
  for (unsigned int i = 0; i < other._size ; i++)
    _array[i] = other._array[i];
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& other){
  if (other == *this)
    return (*this);
  delete[] (_array);
  _array = new T[other._size];
  _size = other._size;

  for (unsigned int i = 0; i < other._size ; i++)
    _array[i] = other._array[i];

  return (*this);
}

template<typename T>
Array<T>::~Array(){
  delete[] _array;
}

template<typename T>
T& Array<T>::operator[](unsigned int n){
  if (n >= _size)
    throw std::out_of_range("out of range");
  return (_array[n]);
}

template<typename T>
const T& Array<T>::operator[](unsigned int n) const{
  if (n >= _size)
    throw std::out_of_range("out of range");
  return (_array[n]);
}

template<typename T>
unsigned int Array<T>::size(void) const{
  return (_size);
}
