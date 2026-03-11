#include "../include/iter.hpp"

template <typename T>
void print(const T& any){
  std::cout << any << std::endl;
}

template <typename T>
void incr(T& any){
  ++any;
}


int main() {
    int array[] = {0, 1, 2, 3};
    iter(array, 4, print<int>);
    iter(array, 4, incr<int>);
    std::cout << std::endl;
    iter(array, 4, print<int>);
    std::cout << std::endl;

    const int array1[] = {0, 1, 2, 3, 4, 5};
    iter(array1, 6, print<int>);
    // iter(array1, 6, incr<int>);
    std::cout << std::endl;

    std::string array2[] = {"Une", "phrase", "random"};
    iter(array2, 3, print<std::string>);
    std::cout << std::endl;

    return (0);
}
