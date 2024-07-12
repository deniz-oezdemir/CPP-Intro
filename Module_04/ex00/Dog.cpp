#include "Dog.hpp"

Dog::Dog(){
	std::cout << "Dog constructor called" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog &src) : Animal(src){
	std::cout << "Dog copy constructor called" << std::endl;
	*this = src;
}

Dog &Dog::operator=(const Dog &assign){
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &assign)
		this->type = assign.type;
	return (*this);
}

Dog::~Dog(){
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const{
	std::cout << "Wuff" << std::endl;
}
