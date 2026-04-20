#include "ScalarConverter.hpp"
#include <iostream>

static t_type	detectType(std::string &literal) {
	(void)literal;
	return (INVALID);
}

static void	convertPseudo(std::string &literal) {
	if (literal == "nan" || literal == "nanf") {
		std::cout << "char: impossible" << std::endl
		<< "int: impossible" << std::endl
		<< "float: nanf" << std::endl
		<< "double: nan" << std::endl;
	}
	if (literal == "+inf" || literal == "+inff") {
		std::cout << "char: impossible" << std::endl
		<< "int: impossible" << std::endl
		<< "float: +inff" << std::endl
		<< "double: +inf" << std::endl;
	}
	if (literal == "-inf" || literal == "-inf") {
		std::cout << "char: impossible" << std::endl
		<< "int: impossible" << std::endl
		<< "float: -inff" << std::endl
		<< "double: -inf" << std::endl;
	}
}

void	ScalarConverter::convert(std::string literal) {
	if (literal == "nan" || literal == "nanf"
		|| literal == "+inf" || literal == "+inff"
		|| literal == "-inf" || literal == "-inff") {
		convertPseudo(literal);
		return ;
	}
	detectType(literal);

}
