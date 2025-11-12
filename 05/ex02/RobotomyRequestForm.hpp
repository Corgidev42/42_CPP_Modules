#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp"
#include <string>
#include <ctime>
class RobotomyRequestForm : public AForm
{
public:
    RobotomyRequestForm(const std::string& target);
    virtual ~RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm &other);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

    virtual void doExecute() const;
};

#endif