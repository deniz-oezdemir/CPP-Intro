#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice(): AMateria("ice"){
	std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(const Ice &src): AMateria(src.getType()){
	std::cout << "Ice copy constructor called" << std::endl;
}

Ice::~Ice(){
	std::cout << "Ice destructor called" << std::endl;
}

Ice &Ice::operator=(const Ice &src){
	std::cout << "Ice copy assignment operator called" << std::endl;
	if (this != &src)
		this->type_ = src.type_;
	return (*this);
}

AMateria *Ice::clone() const {
	std::cout << "Ice cloned" << std::endl;
	return new Ice();
}

void Ice::use(ICharacter &target){
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
