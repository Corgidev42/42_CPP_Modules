#include "Form.hpp"

Form::Form(const std::string& name, int signGrade, int executeGrade)
    : _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
    if (signGrade < 1 || executeGrade < 1)
        throw Form::GradeTooHighException();
    else if (signGrade > 150 || executeGrade > 150)
        throw Form::GradeTooLowException();
}

Form::~Form() {}

Form::Form(const Form &other)
    : _name(other._name), _isSigned(other._isSigned),
      _signGrade(other._signGrade), _executeGrade(other._executeGrade) {}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
        this->_isSigned = other._isSigned;
    return *this;
}

const char* Form::GradeTooHighException::what() const throw() {
    return ("Form grade is too high");
}

const char* Form::GradeTooLowException::what() const throw() {
    return ("Form grade is too low");
}

const std::string& Form::getName() const {
    return _name;
}

bool Form::getIsSigned() const {
    return _isSigned;
}

int Form::getSignGrade() const {
    return _signGrade;
}

int Form::getExecuteGrade() const {
    return _executeGrade;
}

void Form::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > _signGrade)
        throw Form::GradeTooLowException();
    _isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
    os << "Form Name: " << f.getName() << ", Signed: " << (f.getIsSigned() ? "Yes" : "No")
       << ", Sign Grade: " << f.getSignGrade() << ", Execute Grade: " << f.getExecuteGrade() << ".";
    return os;
}
