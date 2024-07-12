#include "Cat.hpp"

Cat::Cat(){
	std::cout << "Cat constructor called" << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat &src) : Animal(src){
	std::cout << "Cat copy constructor called" << std::endl;
	*this = src;
}

Cat &Cat::operator=(const Cat &assign){
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &assign)
		this->type = assign.type;
	return (*this);
}

Cat::~Cat(){
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const{
	std::cout << "Meow" << std::endl;
}
