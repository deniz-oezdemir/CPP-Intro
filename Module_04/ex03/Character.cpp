#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(): name_("anonymous"){
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	std::cout << "Character default constructor called" << std::endl;
}

Character::Character(const std::string &name): name_(name){
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	std::cout << "Character constructor called " << name << std::endl;
}

Character::Character(const Character &src): name_(src.name_){
	for (int i = 0; i < 4; i++)	{
		if (src.inventory[i])
			inventory[i] = src.inventory[i]->clone();
		else
			inventory[i] = NULL;
	}
	std::cout << "Character copy constructor called" << std::endl;
}

Character::~Character(){
	for (int i = 0; i < 4; i++)
		if (this->inventory[i])
			delete this->inventory[i];
	std::cout << "Character destructor called" << std::endl;
}

Character &Character::operator=(const Character &assign)
{
	if (this != &assign)
	{
		const_cast<std::string&>(name_) = assign.name_;
		for (int i = 0; i < 4; i++){
			delete inventory[i];
			inventory[i] = NULL;
		}
		for (int i = 0; i < 4; i++){
			if (assign.inventory[i])
				inventory[i] = assign.inventory[i]->clone();
			else
				inventory[i] = NULL;
		}
	}
	std::cout << "Character copy assignment operator called" << std::endl;
	return *this;
}

std::string const &Character::getName() const {
	return name_;
}

void Character::equip(AMateria *m)
{
	if (!m) {
		std::cout << "Character " << this->name_ << " can not equip invalid NULL Materia" << std::endl;
		return;
	}
	for (int i = 0; i < 4; i++)	{
		if (this->inventory[i] == NULL){
			this->inventory[i] = m;
			std::cout << "Character " << this->name_ << " equipped slot " << i << " with " << m->getType() << std::endl;
			return;
		}
		if (i == 3){
			std::cout << "Character " << this->name_ << "'s inventory is full, can not equip and therefore destroys " << m->getType() << std::endl;
			delete m;
			return;
		}
	}
}

void Character::unequip(int index){
	if (index >= 0 && index < 4 && this->inventory[index] != NULL){
		this->inventory[index] = NULL;
		std::cout << "Character " << this->name_ << " unequipped slot " << index << std::endl;
	}
}

void Character::use(int index, ICharacter &target){
	if (index < 0 || index > 3)
		std::cout << "Character " << this->name_ << "'s inventory has only slots 0 to 3" << std::endl;
	else if (this->inventory[index] == NULL)
		std::cout << "Character " << this->name_ << " has no Materia at slot " << index << std::endl;
	else
		this->inventory[index]->use(target);
}
