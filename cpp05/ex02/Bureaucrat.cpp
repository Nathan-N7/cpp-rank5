// Implementação dos métodos da classe Bureaucrat (ex02)
#include "Bureaucrat.hpp"

// Construtor padrão: nome "Default", nota 150 (menor hierarquia)
Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {

}
// Construtor de cópia: copia nome e nota
Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {

}

// Destrutor: nada especial a limpar
Bureaucrat::~Bureaucrat() {
}

// Operador de atribuição: copia apenas a nota (nome é constante)
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        this->_grade = other.getGrade();
    }
    return *this;
}

// Construtor parametrizado: valida se a nota está entre 1 e 150
Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    this->_grade = grade;
}

// Retorna o nome (atributo constante)
std::string Bureaucrat::getName() const {
    return (this->_name);
}

// Retorna a nota atual
int	Bureaucrat::getGrade() const {
    return (this->_grade);
}

// Retorna mensagem: nota muito alta (menor que 1)
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

// Retorna mensagem: nota muito baixa (maior que 150)
const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

// Sobe na hierarquia: decrementa a nota (ex: 2 -> 1)
void Bureaucrat::incrementGrade() {
    if (_grade - 1 < 1)
        throw GradeTooHighException();
    _grade--;
}

// Desce na hierarquia: incrementa a nota (ex: 2 -> 3)
void Bureaucrat::decrementGrade() {
    if (_grade - 1 > 150)
        throw GradeTooHighException();
    _grade++;
}

// Sobrecarga do operador << para impressão
std::ostream &operator<<(std::ostream &os, const Bureaucrat &b) {
    os << "Name: " << b.getName() << "Grade: " << b.getGrade() << std::endl;
    return (os);
}