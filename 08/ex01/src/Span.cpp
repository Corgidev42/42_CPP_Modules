#include "../include/Span.hpp"
#include <algorithm>
#include <stdexcept>
#include <vector>

Span::Span() : _size(0){}

Span::Span(unsigned int n) : _size(n){}

Span::Span(const Span& other) : _size(other._size){
  std::vector<int>::const_iterator it;
  for (it = other._store.begin(); it != other._store.end() ; ++it )
    _store.push_back(*it);
}

Span& Span::operator=(const Span& other){
  std::vector<int>::const_iterator it;
  _store.clear();
  for (it = other._store.begin(); it != other._store.end() ; ++it)
    _store.push_back(*it);

  return *this;
}

Span::~Span(){}

void Span::addNumber(int number){
  if (_store.size() < _size)
    _store.push_back(number);
  else
    throw std::out_of_range("storage is already filled");
}

unsigned int Span::shortestSpan(void) const{
  if (_store.size() <= 1)
    throw std::logic_error("few element in storage");

  Span copy(*this);
  std::vector<int>::iterator it;
  std::sort(copy._store.begin(), copy._store.end());


  it = copy._store.begin();
  int min = *(it + 1) - *it;
  for (it = copy._store.begin() ; it != copy._store.end() - 1; ++it){
    if ( (*(it + 1) - *it) < min)
      min = *(it + 1) - *it;
  }

  return ((unsigned int)min);
}

unsigned int Span::longestSpan(void) const{
  if (_store.size() <= 1)
    throw std::logic_error("few element in storage");
  const int min = *(std::min_element(_store.begin(), _store.end()));
  const int max = *(std::max_element(_store.begin(), _store.end()));

  return (max - min);
}
