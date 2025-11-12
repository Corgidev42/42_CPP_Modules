#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"
class Bureaucrat;

class Form
{
private:
    const std::string _name;
    bool _isSigned;
    const int _signGrade;
    const int _executeGrade;
public:
    Form(const std::string& name, int signGrade, int executeGrade);
    ~Form();
    Form(const Form &other);
    Form& operator=(const Form& other);

    const std::string& getName() const;
    bool getIsSigned() const;
    int getSignGrade() const;
    int getExecuteGrade() const;

    void beSigned(const Bureaucrat& b);

    class GradeTooHighException : public std::exception
    {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        const char* what() const throw();
    };

};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif