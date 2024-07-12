#pragma once

#include "Animal.hpp"

class Dog : public Animal{
public:
	Dog();
	Dog(const Dog &src);
	Dog &operator=(const Dog &assign);
	virtual ~Dog();

	virtual void makeSound() const;
};
