#include "Animal.hpp"

Animal::Animal() : type("Animal"){
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &src) : type(src.type){
	std::cout << "Animal copy constructor called" << std::endl;
	*this = src;
}

Animal &Animal::operator=(const Animal &assign){
	std::cout << "Animal copy assignment operator called" << std::endl;
	this->type = assign.type;
	return (*this);
}

Animal::~Animal(){
	std::cout << "Animal destructor called" << std::endl;
}

std::string	Animal::getType() const {
	return type;
}

void Animal::makeSound() const {
	std::cout << "Animal noise" << std::endl;
}
