#ifndef A_FORM_HPP
# define A_FORM_HPP

#include <string>
#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"
class Bureaucrat;

class AForm
{
private:
    const std::string _name;
    bool _isSigned;
    const int _signGrade;
    const int _executeGrade;
public:
    AForm(const std::string& name, int signGrade, int executeGrade);
    virtual ~AForm();
    AForm(const AForm &other);
    AForm& operator=(const AForm& other);

    const std::string& getName() const;
    bool getIsSigned() const;
    int getSignGrade() const;
    int getExecuteGrade() const;

    void execute(Bureaucrat const & executor) const;
    virtual void doExecute() const = 0;

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

    class NotSignedException : public std::exception
    {
    public:
        const char* what() const throw();
    };

};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif