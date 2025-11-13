#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <limits>
#include <cctype>
#include <stdexcept>

void ScalarConverter::convert(const std::string& literal) {
    if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'') {
        char c = literal[1];
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
        return;
    }

    if (literal == "inff" || literal == "+inff" || literal == "-inff" || literal == "nanf") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << literal << std::endl;
        std::string double_equivalent = literal.substr(0, literal.length() - 1);
        std::cout << "double: " << double_equivalent << std::endl;
        return;
    }

    if (literal == "inf" || literal == "+inf" || literal == "-inf" || literal == "nan") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << literal << "f" << std::endl;
        std::cout << "double: " << literal << std::endl;
        return;
    }

    try {
        std::string toParse = literal;
        bool hasFloatSuffix = false;

        if (toParse[toParse.length() - 1] == 'f' && toParse.find("inf") == std::string::npos && toParse.find("nan") == std::string::npos) {
            hasFloatSuffix = true;
            toParse = toParse.substr(0, toParse.length() - 1);
        }

        (void) hasFloatSuffix;

        std::stringstream ss(toParse);
        double d;
        ss >> d;
        if (ss.fail() || !ss.eof())
            throw std::invalid_argument("Invalid literal");

        // CHAR
        if (d >= std::numeric_limits<char>::min() && d <= std::numeric_limits<char>::max() && d == static_cast<int>(d)) {
            char c = static_cast<char>(d);
            if (std::isprint(c))
                std::cout << "char: '" << c << "'" << std::endl;
            else
                std::cout << "char: Non displayable" << std::endl;
        } else
            std::cout << "char: impossible" << std::endl;

        // INT
        if (d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max())
            std::cout << "int: " << static_cast<int>(d) << std::endl;
        else
            std::cout << "int: impossible" << std::endl;

        // FLOAT & DOUBLE
        if (std::isnan(d) || std::isinf(d)) {
            std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
            std::cout << "double: " << d << std::endl;
        } else if (std::floor(d) == d) {
            std::cout << std::fixed << std::setprecision(1);
            std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
            std::cout << "double: " << d << std::endl;
            std::cout.unsetf(std::ios::fixed);
        } else {
            std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
            std::cout << "double: " << d << std::endl;
        }

    } catch (const std::exception&) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}