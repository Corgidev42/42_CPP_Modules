#ifndef Intern_HPP
#define Intern_HPP

#include "AForm.hpp"

class AForm;

typedef AForm* (*formCreator)(const std::string& target);

class Intern {
public:
    Intern();
    ~Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);

    AForm* makeForm(const std::string& formName, const std::string& target);
};

#endif // Intern_HPP