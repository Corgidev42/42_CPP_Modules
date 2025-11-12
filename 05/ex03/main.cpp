#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

// Fonction utilitaire pour imprimer des séparateurs
void printSeparator(const std::string& title) {
    std::cout << "\n\n======================================================\n";
    std::cout << "               " << title << "\n";
    std::cout << "======================================================\n";
}

int main() {
    // --------------------------------------------------------------------------
    //                                 PARTIE 1 : TESTS BASIQUES BUREAUCRAT
    // --------------------------------------------------------------------------
    printSeparator("PARTIE 1 : TESTS BASIQUES BUREAUCRAT");

    // Test 1.1: Création et surcharge de l'opérateur <<
    try {
        Bureaucrat high("Boss", 1);
        Bureaucrat middle("Employé", 75);
        Bureaucrat low("Stagiaire", 150);

        std::cout << high << "\n";
        std::cout << middle << "\n";
        std::cout << low << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Erreur inattendue de création (Test 1.1): " << e.what() << "\n";
    }

    // Test 1.2: Exceptions GradeTooHigh/Low à la construction
    try {
        printSeparator("TEST 1.2: Exceptions de construction");
        Bureaucrat tooHigh("Zeus", 0); // Devrait lancer GradeTooHighException
    } catch (const std::exception& e) {
        std::cerr << "Exception attrapée (0): " << e.what() << "\n";
    }

    try {
        Bureaucrat tooLow("Hades", 151); // Devrait lancer GradeTooLowException
    } catch (const std::exception& e) {
        std::cerr << "Exception attrapée (151): " << e.what() << "\n";
    }

    // Test 1.3: Exceptions à l'incrémentation/décrémentation
    try {
        printSeparator("TEST 1.3: Exceptions Incrémenter/Décrémenter");
        Bureaucrat min("LeMinimum", 150);
        std::cout << min;
        min.decrementGrade(); // Devrait lancer GradeTooLowException
    } catch (const std::exception& e) {
        std::cerr << "Exception attrapée (decrementer 150): " << e.what() << "\n";
    }

    try {
        Bureaucrat max("LeMaximum", 1);
        std::cout << max;
        max.incrementGrade(); // Devrait lancer GradeTooHighException
    } catch (const std::exception& e) {
        std::cerr << "Exception attrapée (incrementer 1): " << e.what() << "\n";
    }

    // --------------------------------------------------------------------------
    //                                 PARTIE 2 : TESTS DE CREATION D'AForm
    // --------------------------------------------------------------------------
    printSeparator("PARTIE 2 : TESTS INTERN (makeForm)");

    Intern someRandomIntern;
    AForm* form1 = NULL;
    AForm* form2 = NULL;
    AForm* form3 = NULL;
    AForm* formInvalid = NULL;

    // Test 2.1: Création réussie des 3 types
    std::cout << "\n--- Creation reussie ---\n";
    form1 = someRandomIntern.makeForm("robotomy request", "Bender");
    form2 = someRandomIntern.makeForm("shrubbery creation", "Garden");
    form3 = someRandomIntern.makeForm("presidential pardon", "Kira");

    if (form1) std::cout << *form1 << "\n";
    if (form2) std::cout << *form2 << "\n";
    if (form3) std::cout << *form3 << "\n";

    // Test 2.2: Nom de formulaire invalide
    std::cout << "\n--- Creation echouee ---\n";
    formInvalid = someRandomIntern.makeForm("unknown form", "Nobody");
    if (formInvalid == NULL) {
        std::cout << "Le pointeur est bien NULL pour le formulaire inconnu.\n";
    }

    // --------------------------------------------------------------------------
    //                                 PARTIE 3 : TESTS SIGNER ET EXECUTER
    // --------------------------------------------------------------------------
    printSeparator("PARTIE 3 : TESTS SIGNER ET EXECUTER");

    try {
        Bureaucrat highRank("Zaphod", 5);
        Bureaucrat lowRank("Arthur", 140);
        Bureaucrat middleRank("Ford", 50);

        // --- Cas 3.1 : Signature réussie ---
        std::cout << "\n--- Cas 3.1 : Signature reussie (Presidential Pardon) ---\n";
        if (form3) {
            std::cout << *form3;
            highRank.signForm(*form3); // Zaphod (5) signe Kira (25) -> OK
            std::cout << *form3;
        }

        // --- Cas 3.2 : Signature échouée (grade trop bas) ---
        std::cout << "\n--- Cas 3.2 : Signature echouee (Robotomy Request) ---\n";
        if (form1) {
            std::cout << *form1;
            lowRank.signForm(*form1); // Arthur (140) signe Bender (72) -> Échoue
            std::cout << *form1;
        }

        // --- Cas 3.3 : Exécution réussie (Robotomy Request) ---
        std::cout << "\n--- Cas 3.3 : Execution reussie (Robotomy Request) ---\n";
        if (form1) {
            middleRank.signForm(*form1); // Ford (50) signe Bender (72) -> OK
            std::cout << *form1;
            middleRank.executeForm(*form1); // Ford (50) exécute (45) -> OK
        }

        // --- Cas 3.4 : Exécution échouée (non signé) ---
        std::cout << "\n--- Cas 3.4 : Execution echouee (Shrubbery Creation non signe) ---\n";
        if (form2) {
            std::cout << *form2;
            highRank.executeForm(*form2); // Zaphod (5) exécute (137) MAIS NON SIGNÉ -> Échoue
        }

        // --- Cas 3.5 : Exécution échouée (grade trop bas pour exécution) ---
        std::cout << "\n--- Cas 3.5 : Execution echouee (Presidential Pardon) ---\n";
        if (form3) {
            // Déjà signé par highRank (5)
            std::cout << *form3;
            middleRank.executeForm(*form3); // Ford (50) exécute (5) -> Échoue
        }

    } catch (const std::exception& e) {
        std::cerr << "Erreur inattendue dans la partie 3: " << e.what() << "\n";
    }

    // Nettoyage de la mémoire allouée par l'Intern
    delete form1;
    delete form2;
    delete form3;

    return 0;
}