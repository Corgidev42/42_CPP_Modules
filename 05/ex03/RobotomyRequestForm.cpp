#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm(target, 72, 45) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)

{
    AForm::operator=(other);
    return *this;
}

void RobotomyRequestForm::doExecute() const {
    std::srand(std::time(0));
    std::cout << "Bzzzzzz... Vrrrrrr..." << std::endl;
    if (std::rand() % 2)
        std::cout << getName() << " has been robotomized successfully." << std::endl;
    else
        std::cout << "Robotomy failed on " << getName() << "." << std::endl;
}

AForm* RobotomyRequestForm::create(const std::string& target) {
    return new RobotomyRequestForm(target);}
