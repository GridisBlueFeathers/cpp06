#include "ScalarConverter.hpp"
#include <cctype>
#include <iostream>
#include <cstdint>

static bool	isChar(std::string &literal) {
	if (literal.size() == 1 && !std::isdigit(literal[0]))
		return (true);
	if (literal.size() == 3 && literal[0] == '\'' && literal[2] == '\'')
		return (true);
	return (false);
}

static bool	isInt(std::string &literal) {
	int		i = 0;
	int		hasSign = 0;
	
	if (literal[0] == '-' || literal[0] == '+') {
		i++;
		hasSign = 1;
	}
	if ((int)literal.size() > (10 + hasSign))
		return false;
	while (i < (int)literal.size()) {
		if (!isdigit(literal[i]))
			return false;
		i++;
	}
	return (true);
}

static bool isFloat(std::string &literal) {
	size_t	dot = literal.find('.');
	size_t	i = 0;

	if (literal[0] == '-' || literal[0] == '+')
		i++;
	for (; i < dot; i++) {
		if (!isdigit(literal[i]))
			return (false);
	}
	i++;
	for (; i < literal.size(); i++) {
		if ((!isdigit(literal[i]) && i != literal.size() - 1)
			|| (literal[i] != 'f' && i == literal.size() - 1))
			return (false);
	}
	return (true);
}

static t_type	detectType(std::string &literal) {
	size_t	fIdentifier = literal.find('f');
	size_t	dot = literal.find('.');
	
	if (fIdentifier == std::string::npos && dot == std::string::npos) {
		if (isChar(literal))
			return (CHAR);
		if (isInt(literal))
			return (INT);
	}
	if (dot != std::string::npos && fIdentifier != std::string::npos)
		if (isFloat(literal))
			return (FLOAT);
	if (dot != std::string::npos && fIdentifier == std::string::npos)
		return (DOUBLE);
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

static void convertChar(std::string &literal) {
	char		c = 0;

	if (literal.size() == 1)
		c = literal[0];
	else
		c = literal[1];
	std::cout << "char: ";
	isprint(c)
		? (std::cout << "'" << c << "'" << std::endl)
		: (std::cout << "Non displayable");
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;

}

static void	convertInt(std::string &literal) {
	long	val = atol(literal.c_str());
	
	std::cout << "char: ";
	if (val < 0 || val > 127)
		std::cout << "impossible" << std::endl;
	else 
		isprint(val)
			? (std::cout << "'" << static_cast<char>(val) << "'" << std::endl)
			: (std::cout << "Non displayable" << std::endl);
	std::cout << "int: ";
	if (val < INT32_MIN || val > INT32_MAX)
		std::cout << "impossible";
	else
		std::cout << static_cast<int>(val) << std::endl;
	std::cout << "float: " << static_cast<float>(val) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(val) << ".0" << std::endl;
}

static void	convertFloat(std::string &literal) {
	long double	val = atof(literal.c_str());
	(void)val;
	std::cout << "char: ";
	if (val < 0 || val > 127)
		std::cout << "impossible" << std::endl;
	else
		isprint(val)
			? (std::cout << "'" << static_cast<char>(val) << "'" << std::endl)
			: (std::cout << "Non displayable" << std::endl);
	std::cout << "int: ";
	if (val < INT32_MIN || val > INT32_MAX)
		std::cout << "impossible";
	else
		std::cout << static_cast<int>(val) << std::endl;
}

static void	convertDouble(std::string &literal) {
	long double	val = atof(literal.c_str());
	(void)val;
	std::cout << "char: ";
	if (val < 0 || val > 127)
		std::cout << "impossible" << std::endl;
	else
		isprint(val)
			? (std::cout << "'" << static_cast<char>(val) << "'" << std::endl)
			: (std::cout << "Non displayable" << std::endl);
	std::cout << "int: ";
	if (val < INT32_MIN || val > INT32_MAX)
		std::cout << "impossible";
	else
		std::cout << static_cast<int>(val) << std::endl;
}

void	ScalarConverter::convert(std::string literal) {
	if (literal == "nan" || literal == "nanf"
		|| literal == "+inf" || literal == "+inff"
		|| literal == "-inf" || literal == "-inff") {
		convertPseudo(literal);
		return ;
	}
	if (!literal.size())
		return ;
	switch (detectType(literal)) {
		case (CHAR):
			convertChar(literal);
			break;
		case (INT):
			convertInt(literal);
			break;
		case (FLOAT):
			convertFloat(literal);
			break;
		case (DOUBLE):
			convertDouble(literal);
			break;
		default:
			break;
	}
}
