// Bureaucrat.hpp - Define a classe Bureaucrat (burocrata)
// O burocrata tem um nome constante e uma nota de 1 (maior) a 150 (menor)
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat {
	private:
		// Nome do burocrata (constante, não pode ser alterado)
		const std::string _name;
		// Nota do burocrata (1 = maior hierarquia, 150 = menor)
		int	_grade;
	public:
		// Construtor padrão: nome "Default", nota 150
		Bureaucrat();
		// Construtor parametrizado: define nome e nota
		Bureaucrat(const std::string& name, int grade);
		// Construtor de cópia
		Bureaucrat(const Bureaucrat& other);
		// Destrutor
		~Bureaucrat();
		// Operador de atribuição (copia apenas a nota)
		Bureaucrat &operator=(const Bureaucrat& other);
		// Retorna o nome
		std::string getName() const;
		// Retorna a nota
		int	getGrade() const;
		// Exceção: nota muito alta (menor que 1)
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		// Exceção: nota muito baixa (maior que 150)
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		// Sobe na hierarquia (diminui a nota em 1)
		void incrementGrade();
		// Desce na hierarquia (aumenta a nota em 1)
		void decrementGrade();
};

// Sobrecarga do operador << para impressão
std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

#endif