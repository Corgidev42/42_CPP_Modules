#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern& other) {
    (void)other;
}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

struct FormType {
    std::string name;
    formCreator createFunc;
};

static const FormType formTypes[] = {
    {"shrubbery creation", &ShrubberyCreationForm::create},
    {"robotomy request", &RobotomyRequestForm::create},
    {"presidential pardon", &PresidentialPardonForm::create}
};

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    for (size_t i = 0; i < sizeof(formTypes) / sizeof(formTypes[0]); i++)
    {
        if (formTypes[i].name == formName)
        {
            AForm* newForm = formTypes[i].createFunc(target);

            std::cout << "Intern create " << newForm->getName() << std::endl;
            return (newForm);
        }
    }
    std::cerr << "Intern error : Form name '" << formName << "' is unknown." << std::endl;
    return (NULL);
}