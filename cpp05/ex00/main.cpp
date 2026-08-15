#include "Bureaucrat.hpp"

int main() {
    // Teste 1: burocrata válido, sobe e desce de hierarquia
    try {
        Bureaucrat b("Bob", 2);
        std::cout << b;
        b.incrementGrade();
        std::cout << "Depois de subir: " << b;
        b.decrementGrade();
        std::cout << "Depois de descer: " << b;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    // Teste 2: tentar subir além do grade 1 (deve lançar GradeTooHighException)
    try {
        Bureaucrat b("Alice", 1);
        b.incrementGrade();
    }
    catch (std::exception& e) {
        std::cout << "Erro esperado: " << e.what() << std::endl;
    }

    // Teste 3: tentar descer além do grade 150 (deve lançar GradeTooLowException)
    try {
        Bureaucrat b("Charlie", 150);
        b.decrementGrade();
    }
    catch (std::exception& e) {
        std::cout << "Erro esperado: " << e.what() << std::endl;
    }

    // Teste 4: construir com grade inválida
    try {
        Bureaucrat b("Invalido", 0);
        (void)b;
    }
    catch (std::exception& e) {
        std::cout << "Erro esperado: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b("Invalido2", 151);
        (void)b;
    }
    catch (std::exception& e) {
        std::cout << "Erro esperado: " << e.what() << std::endl;
    }

    // Teste 5: construtor padrão e construtor de cópia
    Bureaucrat def;
    std::cout << def;
    Bureaucrat copy(def);
    std::cout << copy;

    return 0;
}
