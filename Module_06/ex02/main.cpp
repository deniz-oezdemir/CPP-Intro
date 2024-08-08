#include "Classes.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

// Identify the derived class type using reference
void identify(Base &p) {
	try {
		A a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch (std::exception& e) { }
	try {
		B b = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (std::exception& e) { }
	try {
		C c = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch (std::exception& e) { }
}

// Identify the derived class type using pointer
void identify(Base *p) {
	if (p == NULL)
		std::cout << "NULL" << std::endl;
	else if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

// Generate a random derived class object
Base *generate(void) {
	std::srand(std::time(NULL));
	switch (std::rand() % 3) {
		case 0:
			return new A;
		case 1:
			return new B;
		case 2:
			return new C;
		default:
			return NULL;
	}
}

int main() {
	Base *super = generate();
	std::cout << "Identified using pointer:\t";
	identify(super);
	std::cout << "Identified using reference:\t";
	identify(&(*super));
	delete super;
}
