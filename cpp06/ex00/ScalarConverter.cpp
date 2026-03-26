#include "ScalarConverter.hpp"
#include <limits>
#include <iostream>
#include <iomanip>
#include <climits>
#include <cstdlib>
#include <cmath>

static bool isCharLiteral(const std::string &s) {
    return s.length() == 3 && s[0] == '\'' && s[2] == '\'';
}

static bool isPseudoLiteral(const std::string &s) {
    return s == "-inff" || s == "+inff" || s == "nanf"
        || s == "-inf"  || s == "+inf"  || s == "nan";
}

static bool isIntLiteral(const std::string &s) {
    size_t i = 0;
    if (s[i] == '-' || s[i] == '+') i++;
    if (i == s.length()) return false;
    for (; i < s.length(); i++)
        if (s[i] < '0' || s[i] > '9') return false;
    return true;
}

static bool isFloatLiteral(const std::string &s) {
    if (s[s.length() - 1] != 'f') return false;
    std::string trimmed = s.substr(0, s.length() - 1);
    size_t i = 0;
    bool hasDot = false;
    if (trimmed[i] == '-' || trimmed[i] == '+') i++;
    if (i == trimmed.length()) return false;
    for (; i < trimmed.length(); i++) {
        if (trimmed[i] == '.' && !hasDot) { hasDot = true; continue; }
        if (trimmed[i] < '0' || trimmed[i] > '9') return false;
    }
    return hasDot;
}

static bool isDoubleLiteral(const std::string &s) {
    size_t i = 0;
    bool hasDot = false;
    if (s[i] == '-' || s[i] == '+') i++;
    if (i == s.length()) return false;
    for (; i < s.length(); i++) {
        if (s[i] == '.' && !hasDot) { hasDot = true; continue; }
        if (s[i] < '0' || s[i] > '9') return false;
    }
    return hasDot;
}

static void printResults(double d) {
    // char
    if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127)
        std::cout << "char: impossible" << std::endl;
    else if (d < 32 || d == 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;

    // int
    if (std::isnan(d) || std::isinf(d) || d > INT_MAX || d < INT_MIN)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(d) << std::endl;

    // float
    std::cout << std::fixed << std::setprecision(1);
    if (std::isnan(d))
        std::cout << "float: nanf" << std::endl;
    else if (std::isinf(d))
        std::cout << "float: " << (d > 0 ? "+inff" : "-inff") << std::endl;
    else
        std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;

    // double
    if (std::isnan(d))
        std::cout << "double: nan" << std::endl;
    else if (std::isinf(d))
        std::cout << "double: " << (d > 0 ? "+inf" : "-inf") << std::endl;
    else
        std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convert(const std::string &literal) {
    double d;

    if (literal.length() == 1 && !std::isdigit(literal[0])) {
        d = static_cast<double>(literal[0]);
    } else if (isCharLiteral(literal)) {
        d = static_cast<double>(literal[1]);
    } else if (isPseudoLiteral(literal)) {
        if (literal == "nanf" || literal == "nan")
            d = std::numeric_limits<double>::quiet_NaN();
        else if (literal == "+inff" || literal == "+inf")
            d = std::numeric_limits<double>::infinity();
        else
            d = -std::numeric_limits<double>::infinity();
    } else if (isIntLiteral(literal)) {
        d = static_cast<double>(std::atol(literal.c_str()));
    } else if (isFloatLiteral(literal)) {
        d = static_cast<double>(std::atof(literal.c_str()));
    } else if (isDoubleLiteral(literal)) {
        d = std::atof(literal.c_str());
    } else {
        std::cout << "Error: invalid literal" << std::endl;
        return;
    }
    printResults(d);
}