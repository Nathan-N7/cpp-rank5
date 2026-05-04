#pragma once

// PresidentialPardonForm.hpp - Formulário para pedir perdão presidencial
// Herda de AForm e implementa executeAction() para perdoar um alvo
#include "AForm.hpp"

class Bureaucrat;

// Formulário que simula um perdão presidencial para um alvo
// Notas: assinatura = 25, execução = 5 (exige burocrata de alta hierarquia)
class PresidentialPardonForm: public AForm {
    private:
        // Alvo que receberá o perdão presidencial
        std::string _target;
    public:
        // Construtor padrão: alvo "Default"
        PresidentialPardonForm(void);
		// Construtor com alvo específico
		PresidentialPardonForm(std::string const &target);
        // Construtor de cópia
        PresidentialPardonForm(PresidentialPardonForm const &copy);
        // Operador de atribuição
        PresidentialPardonForm  &operator=(const PresidentialPardonForm &other);
        // Destrutor
        ~PresidentialPardonForm(void);
};