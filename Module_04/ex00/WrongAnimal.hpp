#pragma once

#include <string>
#include <iostream>

class WrongAnimal{
protected:
	std::string type;
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &src);
	WrongAnimal &operator=(const WrongAnimal &assign);
	virtual ~WrongAnimal();

	std::string getType() const;

	void makeSound() const;
};
