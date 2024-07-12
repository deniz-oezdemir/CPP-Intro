#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal{
public:
	WrongCat();
	WrongCat(const WrongCat &src);
	WrongCat &operator=(const WrongCat &assign);
	virtual ~WrongCat();

	void makeSound() const;
};
