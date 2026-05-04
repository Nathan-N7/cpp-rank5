// Implementação dos métodos da classe abstrata AForm
#include "AForm.hpp"

// Construtor padrão: valores padrão (nome "Default", nota 150, não assinado)
AForm::AForm() : _name("Default"), _is_signed(false), _sign_grade(150), _execute_grade(150)
{
}

// Construtor parametrizado: valida se as notas estão entre 1 e 150
AForm::AForm(const std::string name, const int sign_grade, const int execute_grade)
    : _name(name), _is_signed(false), _sign_grade(sign_grade), _execute_grade(execute_grade)
{
    if (sign_grade < 1 || execute_grade < 1)
        throw GradeTooHighException();
    if (sign_grade > 150 || execute_grade > 150)
        throw GradeTooLowException();
}

// Construtor de cópia: copia todos os atributos
AForm::AForm(const AForm &other)
    : _name(other._name), _is_signed(other._is_signed), _sign_grade(other._sign_grade), _execute_grade(other._execute_grade)
{
}

// Operador de atribuição: copia apenas o status de assinatura (resto é const)
AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
        _is_signed = other._is_signed;
    return (*this);
}

// Destrutor virtual: classes derivadas podem ter limpeza própria
AForm::~AForm()
{
}

// Tenta assinar: verifica se a nota do burocrata é menor ou igual à nota mínima
void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= _sign_grade)
        _is_signed = true;
    else
        throw GradeTooLowException();
}

// Retorna o nome do formulário
std::string AForm::getName() const
{
    return (_name);
}

// Retorna se o formulário foi assinado
bool AForm::getIsSigned() const
{
    return (_is_signed);
}

// Retorna a nota mínima para assinar
int AForm::getSignGrade() const
{
    return (_sign_grade);
}

// Retorna a nota mínima para executar
int AForm::getExecuteGrade() const
{
    return (_execute_grade);
}

// Executa o formulário: verifica se está assinado e se o burocrata tem nota suficiente
// Depois chama executeAction() (método virtual implementado nas classes derivadas)
void AForm::execute(const Bureaucrat &executor) const
{
    if (_is_signed == false)
        throw FormNotSignedException();
    if (executor.getGrade() > _execute_grade)
        throw GradeTooLowException();

    // Aqui chamamos o método virtual puro que as filhas vão definir
    executeAction();
}

// Retorna mensagem de erro: nota muito alta (menor que 1)
const char *AForm::GradeTooHighException::what() const throw()
{
    return ("Grade too high!");
}

// Retorna mensagem de erro: nota muito baixa (maior que 150)
const char *AForm::GradeTooLowException::what() const throw()
{
    return ("Grade too low!");
}

// Retorna mensagem de erro: tentativa de executar formulário não assinado
const char *AForm::FormNotSignedException::what() const throw()
{
    return ("Form cannot be executed because it is not signed!");
}

// Sobrecarga do operador << para imprimir dados do formulário
std::ostream &operator<<(std::ostream &os, const AForm &f)
{
    os << "Form: " << f.getName() << ", signed: " << (f.getIsSigned() ? "yes" : "no") 
       << ", sign grade: " << f.getSignGrade() << ", exec grade: " << f.getExecuteGrade();
    return (os);
}