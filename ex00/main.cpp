#include "ScalarConverter.hpp"

int main (int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "USE: ./convert [literal]\n";
        return 1;
    }
    ScalarConverter::convert(argv[1]);
    return 0;
}







/*
The ScalarConverter exercise is all about mastering type conversion and string parsing in C++.
It challenges you to handle edge cases, manage errors,
and understand the intricacies of converting between different scalar types.
This exercise is particularly relevant for situations where you need to interpret and manipulate user input,
such as in command-line tools, parsers, or any program that needs to convert and process data provided in various formats.
*/