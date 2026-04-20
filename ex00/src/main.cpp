#include <iostream>
#include "ScalarConverter.hpp"


int main(int argc, const char **argv) {
	if (argc != 2) {
		std::cerr << "Please provide only 1 numeric argument" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
}
