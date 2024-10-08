#include "WrongCat.hpp"

WrongCat::WrongCat(){
	std::cout << "WrongCat constructor called" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src){
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = src;
}

WrongCat &WrongCat::operator=(const WrongCat &assign){
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	if (this != &assign)
		this->type = assign.type;
	return (*this);
}

WrongCat::~WrongCat(){
	std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const{
	std::cout << "Wrong Meow" << std::endl;
}
