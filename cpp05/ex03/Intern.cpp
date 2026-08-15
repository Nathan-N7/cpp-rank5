// Implementação dos métodos do Intern
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// Construtor padrão: intern não tem estado próprio
Intern::Intern(void) {

}

// Construtor de cópia: nada a copiar, mas mantém a Forma Canônica Ortodoxa
Intern::Intern(const Intern &other) {
    (void)other;
}

// Operador de atribuição: idem, nada a copiar
Intern &Intern::operator=(const Intern &other) {
    (void)other;
    return *this;
}

// Destrutor: nada especial a limpar
Intern::~Intern(void) {

}

// Cria o formulário correspondente ao nome pedido.
// Em vez de um if/else if em cadeia, usamos um pequeno array com os nomes
// conhecidos + um switch no índice encontrado: fica mais legível e fácil
// de estender caso surjam novos formulários.
AForm *Intern::makeForm(const std::string &formName, const std::string &target) {
    const std::string formNames[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    AForm *form = NULL;
    int index = -1;

    for (int i = 0; i < 3; i++) {
        if (formName == formNames[i]) {
            index = i;
            break;
        }
    }

    switch (index) {
        case 0:
            form = new ShrubberyCreationForm(target);
            break;
        case 1:
            form = new RobotomyRequestForm(target);
            break;
        case 2:
            form = new PresidentialPardonForm(target);
            break;
        default:
            std::cout << "Error: form \"" << formName << "\" does not exist." << std::endl;
            return (NULL);
    }
    std::cout << "Intern creates " << form->getName() << std::endl;
    return (form);
}
