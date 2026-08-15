#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    // Burocrata de alta hierarquia consegue assinar
    Bureaucrat highGrade("Alice", 1);
    // Burocrata de baixa hierarquia não consegue
    Bureaucrat lowGrade("Bob", 150);

    Form form("Tax Form", 50, 25);

    std::cout << form << std::endl;

    std::cout << "--- Bob tenta assinar (grade insuficiente) ---" << std::endl;
    lowGrade.signForm(form);
    std::cout << form << std::endl;

    std::cout << "--- Alice tenta assinar (grade suficiente) ---" << std::endl;
    highGrade.signForm(form);
    std::cout << form << std::endl;

    std::cout << "--- Testando grades inválidos na construção do Form ---" << std::endl;
    try {
        Form bad("Bad Form", 0, 50);
        (void)bad;
    } catch (std::exception &e) {
        std::cout << "Erro esperado: " << e.what() << std::endl;
    }
    try {
        Form bad("Bad Form", 50, 151);
        (void)bad;
    } catch (std::exception &e) {
        std::cout << "Erro esperado: " << e.what() << std::endl;
    }

    return 0;
}
