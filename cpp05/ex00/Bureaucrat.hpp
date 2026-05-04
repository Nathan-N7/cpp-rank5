#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

// Classe que representa um burocrata com um nome e uma nota (grade)
// A nota vai de 1 (maior hierarquia) a 150 (menor hierarquia)
class Bureaucrat {
	private:
		// Nome do burocrata (constante, não pode ser alterada após criação)
		const std::string _name;
		// Nota do burocrata (1 = maior, 150 = menor)
		int	_grade;
	public:
		// Construtor padrão: cria burocrata com nome "Default" e nota 150
		Bureaucrat();
		// Construtor parametrizado: define nome e nota
		Bureaucrat(const std::string& name, int grade);
		// Construtor de cópia
		Bureaucrat(const Bureaucrat& other);
		// Destrutor
		~Bureaucrat();
		// Operador de atribuição
		Bureaucrat &operator=(const Bureaucrat& other);
		// Retorna o nome do burocrata
		std::string getName() const;
		// Retorna a nota do burocrata
		int	getGrade() const;
		// Exceção lançada quando a nota é maior que o permitido (menor que 1)
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		// Exceção lançada quando a nota é menor que o permitido (maior que 150)
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		// Incrementa a nota em 1 (torna o burocrata mais importante, ex: 2 -> 1)
		void incrementGrade();
		// Decrementa a nota em 1 (torna o burocrata menos importante, ex: 2 -> 3)
		void decrementGrade();
};

// Sobrecarga do operador << para imprimir o burocrata
std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

#endif