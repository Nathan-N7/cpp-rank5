// Implementação dos métodos do RobotomyRequestForm
#include "RobotomyRequestForm.hpp"
#include <cstdlib>

// Construtor padrão: nome fixo "RobotomyRequestForm", notas 72/45, alvo padrão
RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45), _target("default target") {

}

// Construtor com alvo: define o alvo da robotomia
RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {

}

// Construtor de cópia: copia o alvo e chama construtor de cópia da base
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), _target(other._target) {

}

// Operador de atribuição: copia o alvo e delega o resto para AForm::operator=
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

// Destrutor: nada especial a limpar
RobotomyRequestForm::~RobotomyRequestForm(void) {

}

// Faz barulho de britadeira e robotomiza o alvo com 50% de chance de sucesso
void RobotomyRequestForm::executeAction(void) const {
    std::cout << "* DRILLING NOISES *" << std::endl;
    if (std::rand() % 2 == 0)
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "The robotomy of " << _target << " failed." << std::endl;
}
