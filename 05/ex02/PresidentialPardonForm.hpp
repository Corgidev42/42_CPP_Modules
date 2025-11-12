#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP
#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm
{
public:
    PresidentialPardonForm(const std::string& target);
    virtual ~PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm &other);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

    virtual void doExecute() const;
};

#endif