#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include <iostream>

class AAnimal{
protected:
	std::string type;
public:
	AAnimal();
	AAnimal(const AAnimal &src);
	AAnimal &operator=(const AAnimal &assign);
	virtual ~AAnimal();

	std::string getType() const;

	virtual void makeSound() const = 0; //pure virtual function that makes the class abstract
};

#endif
