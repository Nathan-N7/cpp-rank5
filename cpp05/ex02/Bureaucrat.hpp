// Bureaucrat.hpp - Define a classe Bureaucrat (burocrata)
// Burocrata com nome constante e nota de 1 (mais importante) a 150 (menos importante)
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat {
	private:
		// Nome do burocrata (constante, não muda após criação)
		const std::string _name;
		// Nota do burocrata (1 = maior hierarquia, 150 = menor)
		int	_grade;
	public:
		// Construtor padrão: nome "Default", nota 150
		Bureaucrat();
		// Construtor parametrizado: define nome e nota (valida entre 1 e 150)
		Bureaucrat(const std::string& name, int grade);
		// Construtor de cópia
		Bureaucrat(const Bureaucrat& other);
		// Destrutor
		~Bureaucrat();
		// Operador de atribuição (copia apenas a nota, nome é const)
		Bureaucrat &operator=(const Bureaucrat& other);
		// Retorna o nome
		std::string getName() const;
		// Retorna a nota
		int	getGrade() const;
		// Exceção: nota muito alta (tentativa de definir nota < 1)
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		// Exceção: nota muito baixa (tentativa de definir nota > 150)
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		// Sobe na hierarquia: decrementa a nota (ex: 2 -> 1)
		void incrementGrade();
		// Desce na hierarquia: incrementa a nota (ex: 2 -> 3)
		void decrementGrade();
};

// Sobrecarga do operador << para impressão dos dados
std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

#endif