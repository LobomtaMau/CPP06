#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
    (void) other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
    (void) other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}


void ScalarConverter::convert(const std::string &literal) {
    if (isChar(literal))
        printChar(literal);
    else if (isInt(literal))
        printInt(literal);
    else if (isFloat(literal))
        printFloat(literal);
    else if (isDouble(literal))
        printDouble(literal);
    else
        std::cerr << "Invalid literal\n";
}

bool ScalarConverter::isChar(const std::string &literal) {
    return literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]);
}

bool ScalarConverter::isInt(const std::string &literal) {
    char *end;
    long value = std::strtol(literal.c_str(), &end, 10);
    return *end == '\0' && value >= std::numeric_limits<int>::min() && value <=std::numeric_limits<int>::max();

}

bool ScalarConverter::isFloat(const std::string& literal) {
    if (literal == "-inff" || literal == "+inff" || literal == "nanf")
        return true;
    char* end;
    std::strtof(literal.c_str(), &end);
    return *end == 'f' && *(end + 1) == '\0';
}


bool ScalarConverter::isDouble(const std::string& literal) {
    if (literal == "-inf" || literal == "+inf" || literal == "nan")
        return true;
    char* end;
    std::strtod(literal.c_str(), &end);
    return *end == '\0';
}

void ScalarConverter::printChar(const std::string &literal) {
    char c = literal[0];
    if(!isprint(c))
        std::cout << "char: Non displayable\n";
    else
        std::cout << "char: '" << c << "'\n";
    std::cout << "int: " << static_cast<int>(c) << "\n";
    std::cout << "float: " << static_cast<float>(c) << ".0f\n";
    std::cout << "double: " << static_cast<double>(c) << ".0\n";
}

void ScalarConverter::printInt(const std::string &literal) {
    long value = std::strtol(literal.c_str(), NULL, 10);
    if(value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
        std::cout << "int: impossible\n";
    else {
        int val = static_cast<int>(value);
        std::cout << "char: ";
        if (val < 0 || val > 127)
            std::cout << "impossible\n";
        else if (!isprint(val))
            std::cout << "Non displayable\n";
        else
            std::cout << "'" << static_cast<char>(val) << "'\n";
        std::cout << "int: " << val << "\n";
        std::cout << "float: " << static_cast<float>(val) << ".0f\n";
        std::cout << "double: " << static_cast<double>(val) << ".0\n";
    }
}

void ScalarConverter::printFloat(const std::string &literal) {
    float value = std::strtof(literal.c_str(), NULL);
    // if (value > std::numeric_limits<float>::max() || value < -std::numeric_limits<float>::max())
    //     std::cout << "float: impossible\n";
    if (value) {
        std::cout << "char: ";
        if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127)
            std::cout << "impossible\n";
        else if (!isprint(static_cast<int>(value)))
            std::cout << "Non displayable\n";
        else
            std::cout << "'" << static_cast<char>(value) << "'\n";
        std::cout << "int: ";
        if (std::isnan(value) || std::isinf(value) || value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
            std::cout << "impossible\n";
        else
            std::cout << static_cast<int>(value) << "\n";
        std::cout << "float: " << value << "f\n";
        std::cout << "double: " << static_cast<double>(value) << "\n";
    }
    
}

void ScalarConverter::printDouble(const std::string &literal) {
    double value = std::strtod(literal.c_str(), NULL);
    // if (value > std::numeric_limits<double>::max() || value < -std::numeric_limits<double>::max())
    //     std::cout << "double: impossible\n";
    if (value) {
        std::cout << "char: ";
        if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127)
            std::cout << "impossible\n";
        else if (!isprint(static_cast<int>(value)))
            std::cout << "Non displayable\n";
        else
            std::cout << "'" << static_cast<char>(value) << "'\n";

        std::cout << "int: ";
        if (std::isnan(value) || std::isinf(value) || value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
            std::cout << "impossible\n";
        else
            std::cout << static_cast<int>(value) << "\n";

        std::cout << "float: ";
        if (std::isnan(value))
            std::cout << "nanf\n";
        else if (std::isinf(value))
            std::cout << (value > 0 ? "+inff\n" : "-inff\n");
        else if (value > std::numeric_limits<float>::max() || value < -std::numeric_limits<float>::max())
            std::cout << "impossible\n";
        else
            std::cout << static_cast<float>(value) << "f\n";

        std::cout << "double: " << value << "\n";
    }
}
