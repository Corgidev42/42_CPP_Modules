#pragma once

template <typename T>
class Array{
  public:
    Array();
    Array(unsigned int n);
    Array(const Array& other);
    Array<T>& operator=(const Array& other);
    ~Array();

    T& operator[](unsigned int n);
    const T& operator[](unsigned int n) const;

    unsigned int size(void) const;

  private:
    T* _array;
    unsigned int _size;


};

#include "../src/Array.tpp"
