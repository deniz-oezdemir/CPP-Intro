#include "ScavTrap.hpp"

// Constructors
ScavTrap::ScavTrap(): ClapTrap() {
	name_ = "Anonymous";
	hitPoints_ = 100;
	energyPoints_ = 50;
	attackDamage_ = 20;
	std::cout << "Default Constructor of ScavTrap called: ScavTrap " << name_ << " created" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name){
	hitPoints_ = 100;
	energyPoints_ = 50;
	attackDamage_ = 20;
	std::cout << "Constructor of ScavTrap called: ScavTrap " << this->name_ << " created" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap &src) : ClapTrap(src){
	isGuarding_ = src.isGuarding_;
	*this = src;
	std::cout << "Copy Constructor of ScavTrap called ScavTrap" << this->name_ << std::endl;
}

ScavTrap::~ScavTrap(){
	std::cout << "Destructor of ScavTrap called" << std::endl;
}

// Operator
ScavTrap & ScavTrap::operator=(ScavTrap &assign){
	if (this != &assign){
		std::cout << "Assignment operator on ScavTrap " << assign.name_ << " called" << std::endl;
		this->name_ = assign.name_;
		this->hitPoints_ = assign.hitPoints_;
		this->energyPoints_ = assign.energyPoints_;
		this->attackDamage_ = assign.attackDamage_;
	}
	return (*this);
}

void ScavTrap::attack(const std::string& target){
	if (this->energyPoints_ == 0)
		std::cout << "ScavTrap " << this->name_ << " has no energy points and can not attack " << target << std::endl;
	else if (this->hitPoints_ == 0)
		std::cout << "ScavTrap " << this->name_ << " has no hit points and can not attack " << target << std::endl;
	else {
		std::cout << "ScavTrap " << this->name_ << " attacks " << target << " causing " << this->attackDamage_ << " points damage" << std::endl;
		this->energyPoints_--;
	}
}

void	ScavTrap::guardGate(){
	if (this->isGuarding_ == true)
		std::cout << "ScavTrap " << this->name_ << " is already in Gate keeper mode" << std::endl;
	else {
		this->isGuarding_ = true;
		std::cout << "ScavTrap " << this->name_ << " has entered in Gate keeper mode" << std::endl;
	}
}
