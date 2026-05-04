// Implementação dos métodos do PresidentialPardonForm
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

// Construtor padrão: nome fixo, notas 25/5, alvo "Default"
PresidentialPardonForm::PresidentialPardonForm(void) : AForm::AForm("PresidentialPardonForm", 25, 5), _target("Default") {

}

// Construtor com alvo: define quem receberá o perdão
PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm::AForm("PresidentialPardonForm", 25, 5), _target(target) {

}

// Construtor de cópia: copia o alvo e chama construtor de cópia da base
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy) : AForm::AForm(copy), _target(copy._target) {

}

// Destrutor: nada especial a limpar
PresidentialPardonForm::~PresidentialPardonForm(void) {

}