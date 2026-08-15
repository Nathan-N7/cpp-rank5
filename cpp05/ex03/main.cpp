#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    Intern someRandomIntern;
    Bureaucrat boss("Boss", 1);
    AForm *form;

    std::cout << "=== Intern criando os 3 formularios validos ===" << std::endl;
    form = someRandomIntern.makeForm("shrubbery creation", "home");
    boss.signForm(*form);
    boss.executeForm(*form);
    delete form;

    std::cout << std::endl;
    form = someRandomIntern.makeForm("robotomy request", "Bender");
    boss.signForm(*form);
    boss.executeForm(*form);
    delete form;

    std::cout << std::endl;
    form = someRandomIntern.makeForm("presidential pardon", "Fry");
    boss.signForm(*form);
    boss.executeForm(*form);
    delete form;

    std::cout << "\n=== Intern tentando criar um formulario que nao existe ===" << std::endl;
    form = someRandomIntern.makeForm("coffee request", "Boss");
    if (form == NULL)
        std::cout << "form e NULL, como esperado." << std::endl;

    return 0;
}
