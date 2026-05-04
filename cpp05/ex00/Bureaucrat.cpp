// Implementação dos métodos da classe Bureaucrat
#include "Bureaucrat.hpp"

// Construtor padrão: inicializa com nome "Default" e nota 150 (menor hierarquia)
Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {

}
// Construtor de cópia: copia nome e nota de outro burocrata
Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {

}

// Destrutor: nada especial a limpar
Bureaucrat::~Bureaucrat() {
}

// Operador de atribuição: copia apenas a nota (nome é constante e não pode ser alterado)
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        this->_grade = other.getGrade();
    }
    return *this;
}

// Construtor parametrizado: define nome e valida a nota (1 = maior hierarquia, 150 = menor)
Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    this->_grade = grade;
}

// Retorna o nome do burocrata (atributo const, não pode ser alterado)
std::string Bureaucrat::getName() const {
    return (this->_name);
}

// Retorna a nota atual do burocrata
int	Bureaucrat::getGrade() const {
    return (this->_grade);
}

// Retorna mensagem de erro: nota muito alta (valor menor que 1)
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

// Retorna mensagem de erro: nota muito baixa (valor maior que 150)
const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

// Incrementa a nota (diminui o número, ex: 2 -> 1, sobe na hierarquia)
// Nota: 1 é a maior hierarquia possível
void Bureaucrat::incrementGrade() {
    if (_grade - 1 < 1)
        throw GradeTooHighException();
    _grade--;
}

// Decrementa a nota (aumenta o número, ex: 2 -> 3, desce na hierarquia)
// Nota: 150 é a menor hierarquia possível
void Bureaucrat::decrementGrade() {
    if (_grade - 1 > 150)
        throw GradeTooHighException();
    _grade++;
}

// Sobrecarga do operador << para imprimir os dados do burocrata na tela
std::ostream &operator<<(std::ostream &os, const Bureaucrat &b) {
    os << "Name: " << b.getName() << "Grade: " << b.getGrade() << std::endl;
    return (os);
}