#include "Bureaucrat.hpp"

int main() {
    try {
        // Cria burocrata Bob com nota 2 (alta hierarquia)
        Bureaucrat b("Bob", 2);
        // Sobe para nota 1 (máxima hierarquia)
        b.incrementGrade();
        std::cout << "valor: " << b.getGrade() << std::endl;
        // Tenta subir novamente (deve lançar Grade is too high!)
        b.incrementGrade();
    }
    catch (std::exception& e) {
        // Captura e imprime o erro
        std::cout << e.what() << std::endl;
    }
}