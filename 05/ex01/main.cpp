#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
    std::cout << "--- TEST: construction valide ---" << std::endl;
    try {
        Form f1("TopSecret", 10, 20);
        std::cout << f1 << std::endl;
    } catch (std::exception& e) {
        std::cout << "Erreur construction: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST: construction invalide (grades hors limite) ---" << std::endl;
    try {
        Form f2("BadHigh", 0, 10);
        (void)f2;
    } catch (std::exception& e) {
        std::cout << "Expected: " << e.what() << std::endl;
    }
    try {
        Form f3("BadLow", 151, 10);
        (void)f3;
    } catch (std::exception& e) {
        std::cout << "Expected: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST: beSigned avec grades différents ---" << std::endl;
    Form formA("FormA", 50, 50);
    Bureaucrat alice("Alice", 45); // meilleure grade (45 < 50)
    Bureaucrat bob("Bob", 60);     // pire grade (60 > 50)

    std::cout << formA << std::endl;
    try {
        formA.beSigned(bob);
        std::cout << "ERROR: Bob a signé alors qu'il ne devrait pas" << std::endl;
    } catch (std::exception& e) {
        std::cout << "Bob cannot sign: " << e.what() << std::endl;
    }

    try {
        formA.beSigned(alice);
        std::cout << "Alice signed successfully" << std::endl;
    } catch (std::exception& e) {
        std::cout << "Alice couldn't sign: " << e.what() << std::endl;
    }
    std::cout << formA << std::endl;

    std::cout << "\n--- TEST: signForm via Bureaucrat::signForm (interface) ---" << std::endl;
    Bureaucrat charlie("Charlie", 30);
    Form formB("FormB", 25, 25);

    // Simuler la logique de signForm: normalement Bureaucrat appelle form.beSigned(this)
    try {
        formB.beSigned(charlie);
        charlie.signForm(formB);
    } catch (std::exception& e) {
        charlie.signForm(formB);
    }

    std::cout << formB << std::endl;

    std::cout << "\n--- TEST: operator= et copie ---" << std::endl;
    Form original("Original", 75, 75);
    Bureaucrat signer("Signer", 50);
    try { original.beSigned(signer); } catch(...){}
    Form copy("Copy", 75, 75);
    std::cout << "Before assign: " << copy << std::endl;
    copy = original;
    std::cout << "After assign: " << copy << std::endl;

    std::cout << "\n--- TEST: limites d'incrementation/décrementation de Bureaucrat ---" << std::endl;
    Bureaucrat top("Top", 1);
    Bureaucrat low("Low", 150);
    std::cout << top << low;
    try { top.incrementGrade(); } catch (std::exception& e) { std::cout << "Top inc: " << e.what() << std::endl; }
    try { low.decrementGrade(); } catch (std::exception& e) { std::cout << "Low dec: " << e.what() << std::endl; }

    std::cout << "\nTous les tests terminés." << std::endl;
    return 0;
}
