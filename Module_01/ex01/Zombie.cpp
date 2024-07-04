#include "Zombie.hpp"

Zombie::Zombie(std::string	name){
	this->name = name;
}

Zombie::Zombie(){}

Zombie::~Zombie(){
	std::cout << this->name << " destructed" << std::endl;
}

void	Zombie::setName(std::string name){
	this->name = name;
}

void	Zombie::announce(){
	std::cout << this->name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}
