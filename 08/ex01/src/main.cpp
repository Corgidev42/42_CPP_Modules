#include <iostream>
#include <vector>
#include <cstdlib>  // pour rand()
#include <ctime>    // pour time()
#include "../include/Span.hpp" // Remplace par le nom de ton header

int main() {
    std::srand(std::time(NULL)); // initialisation du générateur aléatoire

    const size_t N = 100000;
    Span sp(N);

    // Créons un vector d'entiers aléatoires
    std::vector<int> numbers;
    for (size_t i = 0; i < N; ++i) {
        numbers.push_back(std::rand());
    }

    try {
        // Ajout de tous les nombres avec addRange
        sp.addRange(numbers.begin(), numbers.end());

        // Affichage des résultats des spans
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Exception : " << e.what() << std::endl;
    }

    return 0;
}
