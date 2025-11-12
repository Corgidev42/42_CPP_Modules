#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm(target, 145, 137) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    AForm::operator=(other);
    return *this;
}

void ShrubberyCreationForm::doExecute() const {
    std::ofstream ofs(getName() + "_shrubbery");
    if (!ofs) {
        std::cerr << "Error creating file." << std::endl;
        return;
    }
    ofs << "                                                        .\n"
"                                              .         ;\n"
"                 .              .              ;%     ;;\n"
"                   ,           ,                :;%  %;\n"
"                    :         ;                   :;%;'     .,\n"
"           ,.        %;     %;            ;        %;'    ,;\n"
"             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
"              %;       %;%;      ,  ;       %;  ;%;   ,%;'\n"
"               ;%;      %;        ;%;        % ;%;  ,%;'\n"
"                `%;.     ;%;     %;'         `;%%;.%;'\n"
"                 `:;%.    ;%%. %@;        %; ;@%;%'\n"
"                    `:%;.  :;bd%;          %;@%;'\n"
"                      `@%:.  :;%.         ;@@%;'\n"
"                        `@%.  `;@%.      ;@@%;\n"
"                          `@%%. `@%%    ;@@%;\n"
"                            ;@%. :@%%  %@@%;\n"
"                              %@bd%%%bd%%:;\n"
"                                #@%%%%%:;;\n"
"                                %@@%%%::;\n"
"                                %@@@%(o);  . '\n"
"                                %@@@o%;:(.,'\n"
"                            `.. %@@@o%::;\n"
"                               `)@@@o%::;\n"
"                                %@@(o)::;\n"
"                               .%@@@@%::;\n"
"                               ;%@@@@%::;.\n"
"                              ;%@@@@%%:;;;.\n"
"                          ...;%@@@@@%%:;;;;,..    Gilo97\n";


    ofs.close();
}

AForm* ShrubberyCreationForm::create(const std::string& target) {
    return new ShrubberyCreationForm(target);}