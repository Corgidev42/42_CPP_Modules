#include "../include/easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int main() {
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(2);
    vec.push_back(4);

    std::vector<int>::iterator it = easyfind(vec, 2);
    std::cout << *it << std::endl;

    std::list<int> lst(vec.begin(), vec.end());
    std::list<int>::iterator lit = easyfind(lst, 3);
    std::cout << *lit << std::endl;

    try {
        easyfind(vec, 42);
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
