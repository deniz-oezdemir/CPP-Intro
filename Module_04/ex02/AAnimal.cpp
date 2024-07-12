#include "AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal"){
	std::cout << "AAnimal constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &src) : type(src.type){
	std::cout << "AAnimal copy constructor called" << std::endl;
	*this = src;
}

AAnimal &AAnimal::operator=(const AAnimal &assign){
	std::cout << "AAnimal copy assignment operator called" << std::endl;
	this->type = assign.type;
	return (*this);
}

AAnimal::~AAnimal(){
	std::cout << "AAnimal destructor called" << std::endl;
}

std::string	AAnimal::getType() const {
	return type;
}

/* declaration of makeSound not needed for AAnimal class
void AAnimal::makeSound() const {
	std::cout << "AAnimal noise" << std::endl;
}*/
