// Implementação dos métodos do PresidentialPardonForm
#include "PresidentialPardonForm.hpp"

// Construtor padrão: nome fixo, notas 25/5, alvo "Default"
PresidentialPardonForm::PresidentialPardonForm(void) : AForm::AForm("PresidentialPardonForm", 25, 5), _target("Default") {

}

// Construtor com alvo: define quem receberá o perdão
PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm::AForm("PresidentialPardonForm", 25, 5), _target(target) {

}

// Construtor de cópia: copia o alvo e chama construtor de cópia da base
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy) : AForm::AForm(copy), _target(copy._target) {

}

// Operador de atribuição: copia o alvo e delega o resto para AForm::operator=
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

// Destrutor: nada especial a limpar
PresidentialPardonForm::~PresidentialPardonForm(void) {

}

// Informa que o alvo foi perdoado por Zaphod Beeblebrox
void PresidentialPardonForm::executeAction(void) const {
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
