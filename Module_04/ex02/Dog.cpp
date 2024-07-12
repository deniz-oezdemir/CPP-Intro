#include "Dog.hpp"

Dog::Dog(){
	std::cout << "Dog constructor called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(const Dog &src) : AAnimal(src){
	std::cout << "Dog copy constructor called" << std::endl;
	this->brain = new Brain();
	*this = src;
}

Dog &Dog::operator=(const Dog &assign){
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &assign){
		this->type = assign.type;
		*(this->brain) = *(assign.brain);
	}
	return (*this);
}

Dog::~Dog(){
	std::cout << "Dog destructor called" << std::endl;
	delete this->brain;
}

void Dog::makeSound() const{
	std::cout << "Wuff" << std::endl;
}

Brain *Dog::getBrain() const{
	return (this->brain);
}
