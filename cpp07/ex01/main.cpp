#include "iter.hpp"

// -------- Funções para int --------

void printInt(const int &x)
{
    std::cout << x << " ";
}

void increment(int &x)
{
    x++;
}

// -------- Funções para string --------

void printString(const std::string &str)
{
    std::cout << str << " ";
}

void addExclamation(std::string &str)
{
    str += "!";
}

int main()
{
    std::cout << "=== Teste com int ===" << std::endl;

    int numbers[] = {1, 2, 3, 4, 5};
    std::size_t size = 5;

    std::cout << "Original: ";
    iter(numbers, size, printInt);
    std::cout << std::endl;

    iter(numbers, size, increment);

    std::cout << "Após increment: ";
    iter(numbers, size, printInt);
    std::cout << std::endl << std::endl;

    std::cout << "=== Teste com string ===" << std::endl;

    std::string words[] = {"hello", "world", "templates"};

    std::cout << "Original: ";
    iter(words, 3, printString);
    std::cout << std::endl;

    iter(words, 3, addExclamation);

    std::cout << "Após modificação: ";
    iter(words, 3, printString);
    std::cout << std::endl;

    return 0;
}