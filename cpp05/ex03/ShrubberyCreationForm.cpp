// Implementação dos métodos do ShrubberyCreationForm
#include "ShrubberyCreationForm.hpp"
#include <fstream>

// Construtor padrão: nome fixo, notas 145/137, alvo "default"
ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137), _target("default") {

}

// Construtor com alvo: define onde o "jardim" será plantado
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {

}

// Construtor de cópia: copia o alvo e chama o construtor de cópia da base
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), _target(other._target) {

}

// Operador de atribuição: copia o alvo e delega o resto para AForm::operator=
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

// Destrutor: nada especial a limpar
ShrubberyCreationForm::~ShrubberyCreationForm(void) {

}

// Cria o arquivo "<target>_shrubbery" e escreve uma arvorezinha em ASCII art
void ShrubberyCreationForm::executeAction(void) const {
    std::string filename = _target + "_shrubbery";
    std::ofstream file(filename.c_str());

    if (!file.is_open()) {
        std::cout << "Error: could not create file " << filename << std::endl;
        return;
    }
    file << "         &&&                  " << std::endl;
    file << "        &&&&&                 " << std::endl;
    file << "       &&&&&&&                " << std::endl;
    file << "      &&&&&&&&&               " << std::endl;
    file << "     &&&&&&&&&&&              " << std::endl;
    file << "    &&&&&&&&&&&&&             " << std::endl;
    file << "   &&&&&&&&&&&&&&&            " << std::endl;
    file << "            |||               " << std::endl;
    file << "            |||               " << std::endl;
    file.close();
    std::cout << "Shrubbery planted for " << _target << " in " << filename << std::endl;
}
