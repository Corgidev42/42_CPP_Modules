#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <limits>
#include <stdexcept>

void ScalarConverter::convert(const std::string& literal) {
    if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'') {
        char c = literal[1];
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
    }
    else if (literal == "inff" || literal == "-inff" || literal == "+inff" || literal == "nanf") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << literal << std::endl;
        std::string double_equivalent = literal;
        double_equivalent.pop_back();
        std::cout << "double: " << double_equivalent << std::endl;
    }
    else {
        try {
            size_t idx;
            double d = std::stod(literal, &idx);
            std::cout << idx << std::endl;
            if (idx != literal.length()) {
                throw std::invalid_argument("Invalid literal");
            }

            if (d >= CHAR_MIN && d <= CHAR_MAX && static_cast<int>(d) == d) {
                char c = static_cast<char>(d);
                if (isprint(c))
                    std::cout << "char: '" << c << "'" << std::endl;
                else
                    std::cout << "char: Non displayable" << std::endl;
            } else {
                std::cout << "char: impossible" << std::endl;
            }

            if (d >= INT_MIN && d <= INT_MAX) {
                std::cout << "int: " << static_cast<int>(d) << std::endl;
            } else {
                std::cout << "int: impossible" << std::endl;
            }

            // Cas spéciaux NaN/inf : affichage par défaut (stream gère correctement)
            if (std::isnan(d) || std::isinf(d)) {
                std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
                std::cout << "double: " << d << std::endl;
            } else {
                // Si la valeur est entière, afficher avec .0
                if (std::floor(d) == d) {
                    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
                    std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
                } else {
                    std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
                    std::cout << "double: " << d << std::endl;
                }
            }
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
        }
    }
}