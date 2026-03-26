#include <iostream>
#include "Array.hpp"

int main() {
    std::cout << "=== TESTE 1: Construtor e acesso ===" << std::endl;
    Array<int> a(5);

    for (unsigned int i = 0; i < a.size(); i++) {
        a[i] = i * 10;
        std::cout << "a[" << i << "] = " << a[i] << std::endl;
    }

    std::cout << "\n=== TESTE 2: Copy Constructor ===" << std::endl;
    Array<int> b(a);

    b[0] = 999;

    std::cout << "Original a[0] = " << a[0] << std::endl;
    std::cout << "Copia   b[0] = " << b[0] << std::endl;

    std::cout << "\n=== TESTE 3: Operator= ===" << std::endl;
    Array<int> c;
    c = a;

    c[1] = 555;

    std::cout << "Original a[1] = " << a[1] << std::endl;
    std::cout << "Atribuido c[1] = " << c[1] << std::endl;

    std::cout << "\n=== TESTE 4: Self assignment ===" << std::endl;
    c = c;
    std::cout << "c[1] apos self assign = " << c[1] << std::endl;

    std::cout << "\n=== TESTE 5: Out of bounds ===" << std::endl;
    try {
        std::cout << a[100] << std::endl;
    } catch (std::exception &e) {
        std::cout << "Excecao capturada!" << std::endl;
    }

    std::cout << "\n=== TESTE 6: Array vazio ===" << std::endl;
    Array<int> empty;
    std::cout << "Size = " << empty.size() << std::endl;

    std::cout << "\n=== TESTE 7: Outro tipo (string) ===" << std::endl;
    Array<std::string> strArray(3);

    strArray[0] = "Ola";
    strArray[1] = "Mundo";
    strArray[2] = "!";

    for (unsigned int i = 0; i < strArray.size(); i++) {
        std::cout << strArray[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}