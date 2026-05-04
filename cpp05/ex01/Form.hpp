// Form.hpp - Define a classe Form (formulário) que pode ser assinado por burocratas
#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <exception>
#include "Bureaucrat.hpp"
#include <ostream>

class Bureaucrat;

// Classe que representa um formulário com notas para assinatura e execução
class Form
{
    private:
        // Nome do formulário (constante, não pode ser alterado)
        const std::string _name;
        // Indica se o formulário já foi assinado
        bool    _is_signed;
        // Nota mínima necessária para assinar o formulário (1 = mais importante)
        const   int _sign_grade;
        // Nota mínima necessária para executar o formulário (1 = mais importante)
        const   int _execute_grade;
    public:
        // Construtor padrão
        Form();
        // Construtor com nome e notas de assinatura e execução
        Form(const std::string name, const int sign_grade, const int execute_grade);
        // Construtor de cópia
        Form(const Form &other);
        // Operador de atribuição
        Form &operator=(const Form &other);
        // Destrutor
        ~Form();

        // Tenta assinar o formulário: verifica se a nota do burocrata é suficiente
        void beSigned(const Bureaucrat &b);
        // Retorna o nome do formulário
        std::string getName() const;
		// Retorna se o formulário já foi assinado
		bool		getIsSigned() const;
		// Retorna a nota mínima necessária para assinar
		int			getSignGrade() const;
		// Retorna a nota mínima necessária para executar
		int			getExecuteGrade() const;

        // Exceção: nota muito alta (menor que 1)
        class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		
		// Exceção: nota muito baixa (maior que 150)
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

// Sobrecarga do operador << para imprimir dados do formulário
std::ostream &operator<<(std::ostream &os, const Form &f);

// Fim da guarda de inclusão
#endif