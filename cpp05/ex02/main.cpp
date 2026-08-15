#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    Bureaucrat boss("Boss", 1);      // hierarquia máxima, consegue tudo
    Bureaucrat intern("Intern", 150); // hierarquia mínima, não consegue nada

    ShrubberyCreationForm shrub("home");
    RobotomyRequestForm robot("Bender");
    PresidentialPardonForm pardon("Fry");

    std::cout << "=== Estagiario tentando (deve falhar) ===" << std::endl;
    intern.signForm(shrub);
    intern.executeForm(shrub);

    std::cout << "\n=== Chefao assinando e executando tudo ===" << std::endl;
    boss.signForm(shrub);
    boss.executeForm(shrub);

    boss.signForm(robot);
    boss.executeForm(robot);

    boss.signForm(pardon);
    boss.executeForm(pardon);

    std::cout << "\n=== Executando sem assinar (deve falhar) ===" << std::endl;
    PresidentialPardonForm unsignedPardon("Leela");
    boss.executeForm(unsignedPardon);

    return 0;
}
