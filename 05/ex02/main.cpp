#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        std::cout << "=== Création des bureaucrats ===" << std::endl;
        Bureaucrat boss("Boss", 1);
        Bureaucrat junior("Junior", 150);
        std::cout << boss << std::endl << junior << std::endl;

        std::cout << "=== Création des formulaires ===" << std::endl;
        ShrubberyCreationForm shrub("home");
        RobotomyRequestForm robot("Bender");
        PresidentialPardonForm pardon("Marvin");
        std::cout << shrub << robot << pardon << std::endl;

        std::cout << "=== Tentatives de signature ===" << std::endl;
        junior.signForm(shrub);   // devrait échouer si grade trop bas
        std::cout << shrub << std::endl;
        boss.signForm(shrub);     // devrait réussir
        boss.signForm(robot);
        boss.signForm(pardon);

        std::cout << shrub << robot << pardon << std::endl;


        std::cout << "=== Tentatives d'exécution ===" << std::endl;
        // Exécution avec bureaucrat incompétent
        try { junior.executeForm(shrub); } catch (const std::exception &e) { std::cerr << "Erreur: " << e.what() << std::endl; }

        // Exécution correcte
        boss.executeForm(shrub);

        // Robotomy :essais
        try { boss.executeForm(robot); }
        catch (const std::exception &e) { std::cerr << "Robotomy erreur: " << e.what() << std::endl; }

        // Presidential pardon
        try { boss.executeForm(pardon); }
        catch (const std::exception &e) { std::cerr << "Pardon erreur: " << e.what() << std::endl; }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception globale: " << e.what() << std::endl;
    }

    return 0;
}