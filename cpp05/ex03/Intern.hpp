#pragma once

// Intern.hpp - Estagiário: não tem nome, nem nota, só sabe criar formulários
#include <string>

// Forward declaration: evita include cruzado com AForm.hpp
class AForm;

class Intern {
    public:
        // Construtor padrão
        Intern(void);
        // Construtor de cópia
        Intern(const Intern &other);
        // Operador de atribuição
        Intern &operator=(const Intern &other);
        // Destrutor
        ~Intern(void);

        // Cria um formulário pelo nome, já com o alvo definido.
        // Retorna NULL e imprime um erro se o nome do formulário não existir.
        AForm *makeForm(const std::string &formName, const std::string &target);
};
