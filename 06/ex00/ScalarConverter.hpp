#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

#include <iostream>
#include <limits.h>
#include <string>

class ScalarConverter{
public:
    static void convert(const std::string& literal);

private:
    ScalarConverter();
    ~ScalarConverter();

};
#endif