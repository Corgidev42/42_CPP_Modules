
#include "AForm.hpp"

AForm::AForm(const std::string& name, int signGrade, int executeGrade)
    : _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
    if (signGrade < 1 || executeGrade < 1)
        throw AForm::GradeTooHighException();
    else if (signGrade > 150 || executeGrade > 150)
        throw AForm::GradeTooLowException();
}

AForm::~AForm() {}

AForm::AForm(const AForm &other)
    : _name(other._name), _isSigned(other._isSigned),
      _signGrade(other._signGrade), _executeGrade(other._executeGrade) {}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
        this->_isSigned = other._isSigned;
    return *this;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return ("AForm grade is too high");
}

const char* AForm::GradeTooLowException::what() const throw() {
    return ("AForm grade is too low");
}

const std::string& AForm::getName() const {
    return _name;
}

bool AForm::getIsSigned() const {
    return _isSigned;
}

int AForm::getSignGrade() const {
    return _signGrade;
}

int AForm::getExecuteGrade() const {
    return _executeGrade;
}

void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > _signGrade)
        throw AForm::GradeTooLowException();
    _isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const AForm& f) {
    os << "AForm Name: " << f.getName() << ", Signed: " << (f.getIsSigned() ? "Yes" : "No")
       << ", Sign Grade: " << f.getSignGrade() << ", Execute Grade: " << f.getExecuteGrade() << "." << std::endl;
    return os;
}

void AForm::execute(Bureaucrat const & executor) const {
    if (!_isSigned)
        throw std::runtime_error("Form is not signed");
    if (executor.getGrade() > _executeGrade)
        throw AForm::GradeTooLowException();
    doExecute();
}

