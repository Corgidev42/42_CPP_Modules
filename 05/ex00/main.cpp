#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b1("even", -1);
        b1.incrementGrade();
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat b2("vincent", 100);
        b2.decrementGrade();
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "caca" << std::endl;
}
