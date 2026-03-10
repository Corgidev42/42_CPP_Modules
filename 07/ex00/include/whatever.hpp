#pragma once

template <typename T>
void swap(T& a, T& b){
  T temp;
  temp = a;
  a = b;
  b = temp;
}

template <typename T>
T min(const T& a, const T& b){
  return (a < b ? a : b);
  // Si égalité, retourne le second
  return (a < b ? a : (a == b ? b : b));
}

template <typename T>
T max(const T& a, const T& b){
  // Si égalité, retourne le second
  return (a > b ? a : (a == b ? b : b));
}
