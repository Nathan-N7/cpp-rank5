// Implementação dos métodos da classe Form
#include "Form.hpp"

// Construtor padrão: formulário com valores padrão (nota 150, não assinado)
Form::Form() : _name("Default Form"), _is_signed(false), _sign_grade(150), _execute_grade(150){

}

// Destrutor: nada especial a limpar
Form::~Form(){

}

// Construtor parametrizado: valida se as notas estão entre 1 e 150
Form::Form(const std::string name, const int sign_grade, const int execute_grade) : _name(name), _is_signed(false), _sign_grade(sign_grade), _execute_grade(execute_grade) {
    if (sign_grade < 1 || execute_grade < 1)
        throw Form::GradeTooHighException();
    if (sign_grade > 150 || execute_grade > 150)
        throw Form::GradeTooLowException();
}

// Construtor de cópia: copia todos os atributos do outro formulário
Form::Form(const Form &other) : _name(other._name), _is_signed(other._is_signed), _sign_grade(other._sign_grade), _execute_grade(other._execute_grade) {

}

// Operador de atribuição: copia apenas o status de assinatura (nome e notas são constantes)
Form &Form::operator=(const Form &other) {
    if (this != &other) {
        this->_is_signed = other._is_signed;
    }
    return *this;
}

// Tenta assinar o formulário: verifica se a nota do burocrata é menor ou igual à nota mínima
void Form::beSigned(const Bureaucrat &b) {
    if (b.getGrade() <= this->_sign_grade) {
        this->_is_signed = true;
    } else {
        throw Form::GradeTooLowException();
    }
}

// Retorna o nome do formulário (atributo const)
std::string Form::getName() const {
    Form(_name);
}

// Retorna se o formulário foi assinado
bool    Form::getIsSigned() const {
    return (_is_signed);
}

// Retorna a nota mínima necessária para assinar
int Form::getSignGrade() const {
    return (_sign_grade);
}

// Retorna a nota mínima necessária para executar
int Form::getExecuteGrade() const {
    return (_execute_grade);
}

// Retorna mensagem de erro: nota muito alta (menor que 1)
const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

// Retorna mensagem de erro: nota muito baixa (maior que 150)
const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}

// Sobrecarga do operador << para imprimir os dados do formulário
std::ostream &operator<<(std::ostream &os, const Form &f) {
	os << "Name: " << f.getName() << " isSigned: " << f.getIsSigned() << " SignGrade: " << f.getSignGrade() << " ExecuteGrade: " << f.getExecuteGrade() << std::endl;
	return (os);
}