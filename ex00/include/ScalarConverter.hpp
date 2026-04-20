#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>

typedef enum e_type {
	INVALID,
	CHAR,
	INT,
	FLOAT,
	DOUBLE
}	t_type;

class ScalarConverter {
	public:
		static void	convert(std::string literal); 
};

#endif
