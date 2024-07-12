#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal{
private:
	Brain *brain;
public:
	Dog();
	Dog(const Dog &src);
	Dog &operator=(const Dog &assign);
	virtual ~Dog();

	virtual void makeSound() const;

	Brain *getBrain() const;
};
