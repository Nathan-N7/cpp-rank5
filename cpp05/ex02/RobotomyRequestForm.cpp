// Implementação dos métodos do RobotomyRequestForm
#include "RobotomyRequestForm.hpp"

// Construtor padrão: nome fixo "RobotomyRequestForm", notas 72/45, alvo padrão
RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45), _target("default target") {

}

// Construtor com alvo: define o alvo da robotomia
RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {

}

// Construtor de cópia: copia o alvo e chama construtor de cópia da base
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), _target(other._target) {

}

// Destrutor: nada especial a limpar
RobotomyRequestForm::~RobotomyRequestForm(void) {
    
}