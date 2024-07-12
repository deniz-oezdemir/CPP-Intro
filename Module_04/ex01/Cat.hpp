#pragma once

#include "Animal.hpp"

class Cat : public Animal{
public:
	Cat();
	Cat(const Cat &src);
	Cat &operator=(const Cat &assign);
	virtual ~Cat();

	virtual void makeSound() const;
};
