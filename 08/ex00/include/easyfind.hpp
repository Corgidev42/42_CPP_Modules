#pragma once

template <typename T>
typename T::iterator easyfind(T& container, int numberToFind);

template <typename T>
typename T::const_iterator easyfind(const T& container, int numberToFind);

#include "easyfind.tpp"
