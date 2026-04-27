#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <stdlib.h>
#include <iostream>

Base::~Base(){};

Base	*generate(void) {
	Base	*res = NULL;

	switch (rand() % 3) {
		case(0):
			return (new A());
		case(1):
			return (new B());
		case(2):
			return (new C());
	}

	return (res);
}

void	identify(Base *ptr) {
	if (dynamic_cast<A *>(ptr))
		std::cout << "A" << std::endl;
	if (dynamic_cast<B *>(ptr))
		std::cout << "B" << std::endl;
	if (dynamic_cast<C *>(ptr))
		std::cout << "C" << std::endl;
}

void	identify(Base &ref) {
	std::string res;
	try {
		A &a = dynamic_cast<A &>(ref);
		(void)a;
		res = "A";
	} catch(std::exception &e) {}
	try {
		B &b = dynamic_cast<B &>(ref);
		(void)b;
		res = "B";
	} catch(std::exception &e) {}
	try {
		C &c = dynamic_cast<C &>(ref);
		(void)c;
		res = "C";
	} catch(std::exception &e) {}
	std::cout << res << std::endl;
}
