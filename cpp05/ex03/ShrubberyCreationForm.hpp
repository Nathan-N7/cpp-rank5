#pragma once

// ShrubberyCreationForm.hpp - Formulário que planta um "jardim" ASCII num arquivo
// Herda de AForm e implementa executeAction() para criar o arquivo <target>_shrubbery
#include "AForm.hpp"

// Formulário que cria um arquivo com uma árvore em ASCII art
// Notas: assinatura = 145, execução = 137
class ShrubberyCreationForm : public AForm {
    private:
        // Alvo: nome usado para montar o arquivo "<target>_shrubbery"
        std::string _target;
    public:
        // Construtor padrão: usa target "default"
        ShrubberyCreationForm(void);
        // Construtor com alvo específico
        ShrubberyCreationForm(const std::string &target);
        // Construtor de cópia
        ShrubberyCreationForm(const ShrubberyCreationForm &other);
        // Operador de atribuição
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
        // Destrutor
        ~ShrubberyCreationForm(void);

        // Implementação do método virtual puro: cria o arquivo com a árvore ASCII
        void executeAction(void) const;
};
