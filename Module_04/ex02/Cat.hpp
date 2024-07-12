#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal{
private:
	Brain *brain;
public:
	Cat();
	Cat(const Cat &src);
	Cat &operator=(const Cat &assign);
	virtual ~Cat();

	virtual void makeSound() const;

	Brain *getBrain() const;
};
