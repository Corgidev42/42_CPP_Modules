#pragma once

#include <stdexcept>
#include <vector>

class Span{
public:
  Span();
  Span(unsigned int n);
  Span(const Span& other);
  Span& operator=(const Span& other);
  ~Span();

  void addNumber(int number);
  unsigned int shortestSpan(void) const;
  unsigned int longestSpan(void) const;

  template<typename It>
  void addRange(It begin, It end){
    for (It it = begin; it != end; ++it){
      if (_store.size() < _size)
        _store.push_back(*it);
      else
        throw std::out_of_range("storage is already filled");
    }
  }


private:
  std::vector<int> _store;
  unsigned int _size;
};
