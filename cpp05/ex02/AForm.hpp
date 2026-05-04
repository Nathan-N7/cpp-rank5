// AForm.hpp - Classe abstrata base para todos os formulários
// Diferente do Form (ex01), esta classe é abstrata (tem método virtual puro)
#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

// Classe abstrata: não pode ser instanciada diretamente
// Serve de base para ShrubberyCreationForm, RobotomyRequestForm, etc.
class AForm
{
    private:
        // Nome do formulário (constante)
        const std::string _name;
        // Indica se o formulário foi assinado
        bool    _is_signed;
        // Nota mínima para assinar (1 = mais importante)
        const   int _sign_grade;
        // Nota mínima para executar (1 = mais importante)
        const   int _execute_grade;
    public:
        // Construtor padrão
        AForm();
        // Construtor parametrizado: define nome e notas
        AForm(const std::string name, const int sign_grade, const int execute_grade);
        // Construtor de cópia
        AForm(const AForm &other);
        // Operador de atribuição
        AForm &operator=(const AForm &other);
        // Destrutor virtual (necessário para classes abstratas)
        virtual ~AForm();

        // Método virtual puro: cada formulário derivado implementa sua própria execução
        virtual void executeAction() const = 0;
        // Retorna o nome do formulário
        std::string getName() const;
        // Retorna se o formulário foi assinado
        bool        getIsSigned() const;
        // Retorna a nota mínima para assinar
        int         getSignGrade() const;
        // Retorna a nota mínima para executar
        int         getExecuteGrade() const;
        // Tenta assinar o formulário (verifica se a nota do burocrata é suficiente)
        void beSigned(const Bureaucrat &b);
        // Executa o formulário: verifica se está assinado e se o burocrata tem nota suficiente
        void execute(Bureaucrat const & executor) const;

        // Exceção: nota muito alta (menor que 1)
        class GradeTooHighException : public std::exception {
            public: virtual const char *what() const throw();
        };
        // Exceção: nota muito baixa (maior que 150)
        class GradeTooLowException : public std::exception {
            public: virtual const char *what() const throw();
        };
        // Exceção: tentativa de executar formulário não assinado
        class FormNotSignedException : public std::exception {
            public: virtual const char *what() const throw();
        };
};

// Sobrecarga do operador << para imprimir dados do formulário
std::ostream &operator<<(std::ostream &os, const AForm &f);

// Fim da guarda de inclusão
#endif