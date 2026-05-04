#include "Bureaucrat.hpp"

int main() {
    try {
        // Cria burocrata Bob com nota 2 (hierarquia alta)
        Bureaucrat b("Bob", 2);
        // Incrementa a nota (2 -> 1, agora é o mais alto)
        b.incrementGrade();
        std::cout << "valor: " << b.getGrade() << std::endl;
        // Tenta incrementar novamente (1 -> 0, deve lançar exceção de nota muito alta)
        b.incrementGrade();
    }
    catch (std::exception& e) {
        // Captura e imprime qualquer exceção lançada
        std::cout << e.what() << std::endl;
    }
}