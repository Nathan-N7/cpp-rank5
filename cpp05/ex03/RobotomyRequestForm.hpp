#pragma once

// RobotomyRequestForm.hpp - Formulário para solicitar uma robotomia
// Herda de AForm e implementa executeAction() para simular uma cirurgia robótica
#include "AForm.hpp"

// Formulário que simula uma tentativa de robotomizar um alvo
// Notas: assinatura = 72, execução = 45
class RobotomyRequestForm : public AForm {
    private:
        // Alvo da robotomia (quem vai ser "operado")
        std::string _target;
    public:
        // Construtor padrão: usa target "default target"
        RobotomyRequestForm(void);
        // Construtor com alvo específico
        RobotomyRequestForm(const std::string target);
        // Construtor de cópia
        RobotomyRequestForm(const RobotomyRequestForm &other);
        // Operador de atribuição
        RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
        // Destrutor
        ~RobotomyRequestForm(void);

        // Implementação do método virtual puro: faz barulho de britadeira
        // e robotomiza o alvo com 50% de chance de sucesso
        void executeAction(void) const;
};
