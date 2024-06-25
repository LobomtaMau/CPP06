#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <limits>


class ScalarConverter {
    public:
        static void convert(const std::string &literal);

    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);
        ~ScalarConverter();

        static bool isChar(const std::string &literal);
        static bool isInt(const std::string &literal);
        static bool isFloat(const std::string &literal);
        static bool isDouble(const std::string &literal);

        static void printChar(const std::string &literal);
        static void printInt(const std::string &literal);
        static void printFloat(const std::string &literal);
        static void printDouble(const std::string &literal);

};


#endif