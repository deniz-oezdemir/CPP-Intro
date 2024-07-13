#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(){
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(const std::string &type_): type_(type_){
	std::cout << "AMateria constructor called " << type_ << std::endl;
}

AMateria::AMateria(const AMateria &src)
{
    *this = src;
    std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria::~AMateria(){
	std::cout << "AMateria destructor called" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &src)
{
    this->type_ = src.getType();
    std::cout << "AMateria assignment operator called" << std::endl;
    return *this;
}

std::string const &AMateria::getType() const {
	return this->type_;
}

void AMateria::use(ICharacter &target){
	std::cout << "AMateria used on " << target.getName() << std::endl;
}
