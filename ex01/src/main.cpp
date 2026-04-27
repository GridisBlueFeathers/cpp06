#include "Serializer.hpp"
#include <iostream>

int	main() {
	Data		a = {.someString = "yo", .someNumber = 5};

	std::cout << "someString = " << a.someString << std::endl
		<< "someNumber = " << a.someNumber << std::endl;

	uintptr_t	serialized = Serializer::serialize(&a);
	Data		*ptr = Serializer::deserialize(serialized);

	std::cout << "someString = " << ptr->someString << std::endl
		<< "someNumber = " << ptr->someNumber << std::endl;

	if (a.someString == ptr->someString
		&& a.someNumber == ptr->someNumber)
		std::cout << "everything seems to have went fine" << std::endl;
	else
		std::cout << "something went wrong" << std::endl;
}
