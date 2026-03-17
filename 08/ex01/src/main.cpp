#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "../include/Span.hpp"

int main() {
    std::cout << "=== Basic test (5 numbers) ===" << std::endl;
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    std::cout << "\n=== Test with 10,000 numbers (addRange) ===" << std::endl;
    std::srand(std::time(NULL));

    const size_t N = 10000;
    Span sp2(N);

    std::vector<int> numbers;
    for (size_t i = 0; i < N; ++i) {
        numbers.push_back(std::rand());
    }

    try {
        sp2.addRange(numbers.begin(), numbers.end());
        std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
