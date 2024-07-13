#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure(): AMateria("cure"){
	std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(const Cure &src): AMateria(src.getType()){
	std::cout << "Cure copy constructor called" << std::endl;
}

Cure::~Cure(){
	std::cout << "Cure destructor called" << std::endl;
}

Cure &Cure::operator=(const Cure &src){
	std::cout << "Cure copy assignment operator called" << std::endl;
	if (this != &src)
		this->type_ = src.type_;
	return (*this);
}

AMateria *Cure::clone() const {
	std::cout << "Cure cloned" << std::endl;
	return new Cure();
}

void Cure::use(ICharacter &target){
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
