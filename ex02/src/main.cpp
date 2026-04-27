#include "Base.hpp"
#include <cstdlib>
#include <ctime>

int main() {
	srand(time(NULL));

	Base *ptr = generate();
	Base &ref = *ptr;

	identify(ptr);
	identify(ref);

	delete ptr;
}
