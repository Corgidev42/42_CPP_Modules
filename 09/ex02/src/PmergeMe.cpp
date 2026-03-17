#include "PmergeMe.hpp"
#include "vector_ford_johnson.hpp"
#include "list_ford_johnson.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <cctype>
#include <climits>
#include <cstdlib>
#include <sys/time.h>

typedef std::vector<unsigned int> vui;
typedef std::list<unsigned int> lui;

static long getMicroseconds()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000L + tv.tv_usec;
}

static void printSequence(const vui& v)
{
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i];
        if (i + 1 < v.size())
            std::cout << " ";
    }
    std::cout << std::endl;
}

int runPmergeMe(int argc, char* argv[])
{
    if (argc <= 1) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    vui vectorList;
    lui listList;

    for (int i = 1; i < argc; i++) {
        std::string arg(argv[i]);
        if (arg.empty()) {
            std::cerr << "Error" << std::endl;
            return 1;
        }
        for (size_t j = 0; j < arg.size(); ++j) {
            if (!std::isdigit(static_cast<unsigned char>(arg[j]))) {
                std::cerr << "Error" << std::endl;
                return 1;
            }
        }
        unsigned long n = std::strtoul(arg.c_str(), NULL, 10);
        if (n > static_cast<unsigned long>(UINT_MAX)) {
            std::cerr << "Error" << std::endl;
            return 1;
        }
        if (n == 0) {
            std::cerr << "Error" << std::endl;
            return 1;
        }
        vectorList.push_back(static_cast<unsigned int>(n));
        listList.push_back(static_cast<unsigned int>(n));
    }

    std::cout << "Before: ";
    printSequence(vectorList);

    long startVec = getMicroseconds();
    vui sortedVector = fordJohnson(vectorList);
    long endVec = getMicroseconds();

    std::cout << "After: ";
    printSequence(sortedVector);

    long timeVec = endVec - startVec;
    std::cout << "Time to process a range of " << vectorList.size()
              << " elements with std::vector : "
              << timeVec << " us" << std::endl;

    long startList = getMicroseconds();
    lui sortedList = fordJohnson(listList);
    long endList = getMicroseconds();

    long timeList = endList - startList;
    std::cout << "Time to process a range of " << listList.size()
              << " elements with std::list : "
              << timeList << " us" << std::endl;
    return 0;
}
