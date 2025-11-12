// main.cpp
#include "Bureaucrat.hpp"

int main() {
    std::cout << "===== Création valide =====" << std::endl;
    try {
        Bureaucrat b1("Alice", 42);
        std::cout << b1 << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    std::cout << "\n===== Création invalide (grade trop bas) =====" << std::endl;
    try {
        Bureaucrat b2("Bob", 151);
    } catch (std::exception& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    std::cout << "\n===== Création invalide (grade trop haut) =====" << std::endl;
    try {
        Bureaucrat b3("Charlie", 0);
    } catch (std::exception& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    std::cout << "\n===== Incrémentation OK =====" << std::endl;
    try {
        Bureaucrat b4("Diane", 2);
        std::cout << b4 << std::endl;
        b4.incrementGrade(); // devient 1
        std::cout << b4 << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    std::cout << "\n===== Incrémentation interdite (trop haut) =====" << std::endl;
    try {
        Bureaucrat b5("Eve", 1);
        std::cout << b5 << std::endl;
        b5.incrementGrade(); // erreur attendue
    } catch (std::exception& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    std::cout << "\n===== Décrémentation OK =====" << std::endl;
    try {
        Bureaucrat b6("Frank", 149);
        std::cout << b6 << std::endl;
        b6.decrementGrade(); // devient 150
        std::cout << b6 << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    std::cout << "\n===== Décrémentation interdite (trop bas) =====" << std::endl;
    try {
        Bureaucrat b7("Grace", 150);
        std::cout << b7 << std::endl;
        b7.decrementGrade(); // erreur attendue
    } catch (std::exception& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    std::cout << "\n===== Test de copie et assignation =====" << std::endl;
    try {
        Bureaucrat original("Hank", 10);
        Bureaucrat copy(original);
        Bureaucrat assigned = copy;
        std::cout << "Original: " << original << std::endl;
        std::cout << "Copie   : " << copy << std::endl;
        std::cout << "Assigné : " << assigned << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    return 0;
}