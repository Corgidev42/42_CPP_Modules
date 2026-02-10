#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <cctype>
#include <climits>
#include <sys/time.h>

#include "vector_ford_johnson.hpp"
#include "list_ford_johnson.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"

typedef std::vector<unsigned int> vui;
typedef std::list<unsigned int>   lui;

/*
** Time in microseconds
*/
static long getMicroseconds()
{
    timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000L + tv.tv_usec;
}

/*
** Print vector
*/
static void printVector(const vui& v)
{
    std::cout << "[";
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << GREEN << v[i] << RESET;
        if (i + 1 < v.size())
            std::cout << ", ";
    }
    std::cout << "]\n\n";
}

/*
** Print list
*/
static void printList(const lui& l)
{
    std::cout << "[";
    lui::const_iterator it = l.begin();
    while (it != l.end()) {
        std::cout << GREEN << *it << RESET;
        ++it;
        if (it != l.end())
            std::cout << ", ";
    }
    std::cout << "]\n\n";
}

int main(int argc, char* argv[])
{
    if (argc <= 1) {
        std::cerr << "Need at least 1 number.\n";
        return 1;
    }

    vui vectorList;
    lui listList;

    // Parse arguments
    for (int i = 1; i < argc; i++) {
        std::string arg(argv[i]);
        if (arg.empty()) {
            std::cerr << "Invalid number: empty input.\n";
            return 2;
        }
        for (size_t j = 0; j < arg.size(); ++j) {
            if (!std::isdigit(static_cast<unsigned char>(arg[j]))) {
                std::cerr << "Invalid number: only unsigned int allowed.\n";
                return 2;
            }
        }
        unsigned long n = std::strtoul(arg.c_str(), NULL, 10);
        if (n > UINT_MAX) {
            std::cerr << "Invalid number: exceeds unsigned int range.\n";
            return 2;
        }
        vectorList.push_back(static_cast<unsigned int>(n));
        listList.push_back(static_cast<unsigned int>(n));
    }

    std::cout << "\n===== INPUT =====\n";
    printVector(vectorList);

    /*
    ** =============================
    **      VECTOR FORD–JOHNSON
    ** =============================
    */
    long startVec = getMicroseconds();
    vui sortedVector = fordJohnson(vectorList);
    long endVec = getMicroseconds();

    std::cout << "===== VECTOR RESULT =====\n";
    printVector(sortedVector);

    long timeVec = endVec - startVec;
    std::cout << "Time to process " << vectorList.size()
              << " elements with std::vector : "
              << timeVec << " µs\n\n";


    /*
    ** =============================
    **        LIST FORD–JOHNSON
    ** =============================
    */
    long startList = getMicroseconds();
    lui sortedList = fordJohnson(listList);
    long endList = getMicroseconds();

    std::cout << "===== LIST RESULT =====\n";
    printList(sortedList);

    long timeList = endList - startList;
    std::cout << "Time to process " << listList.size()
              << " elements with std::list : "
              << timeList << " µs\n\n";


    /*
    ** =============================
    **       PERFORMANCE SUMMARY
    ** =============================
    */
    std::cout << "===== SUMMARY =====\n";
    std::cout << "Vector : " << timeVec  << " µs\n";
    std::cout << "List   : " << timeList << " µs\n\n";

    return 0;
}