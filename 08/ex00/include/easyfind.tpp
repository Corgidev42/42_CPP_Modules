#include "easyfind.hpp"
#include <stdexcept>

template<typename T>
typename T::iterator easyfind(T& container, int numberToFind){
  typename T::iterator it;
  for (it = container.begin(); it != container.end() ; ++it){
    if (*it == numberToFind)
      return it;
  }
  throw std::runtime_error("no matching value");
}
