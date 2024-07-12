#include "Cat.hpp"

Cat::Cat(){
	std::cout << "Cat constructor called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat &src) : AAnimal(src){
	std::cout << "Cat copy constructor called" << std::endl;
	this->brain = new Brain();
	*this = src;
}

Cat &Cat::operator=(const Cat &assign){
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &assign){
		this->type = assign.type;
		*(this->brain) = *(assign.brain);
	}
	return (*this);
}

Cat::~Cat(){
	std::cout << "Cat destructor called" << std::endl;
	delete this->brain;
}

void Cat::makeSound() const{
	std::cout << "Meow" << std::endl;
}

Brain *Cat::getBrain() const{
	return (this->brain);
}
