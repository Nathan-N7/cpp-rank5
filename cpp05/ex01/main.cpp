#include "Bureaucrat.hpp"

int main() {
    try {
        // Cria burocrata Bob com nota 2 (alta hierarquia)
        Bureaucrat b("Bob", 2);
        // Incrementa a nota (2 -> 1, maior hierarquia possível)
        b.incrementGrade();
        std::cout << "valor: " << b.getGrade() << std::endl;
        // Tenta incrementar novamente (1 -> 0, deve lançar exceção)
        b.incrementGrade();
    }
    catch (std::exception& e) {
        // Captura e imprime erro (Grade is too high!)
        std::cout << e.what() << std::endl;
    }
}