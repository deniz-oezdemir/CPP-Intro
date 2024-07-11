#include "FragTrap.hpp"

// Constructors
FragTrap::FragTrap(): ClapTrap() {
	name_ = "FragTrap Anonymous";
	hitPoints_ = 100;
	energyPoints_ = 100;
	attackDamage_ = 30;
	std::cout << "Default Constructor of FragTrap called: " << name_ << " created" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name){
	hitPoints_ = 100;
	energyPoints_ = 100;
	attackDamage_ = 30;
	std::cout << "Constructor of FragTrap called: " << this->name_ << " created" << std::endl;
}

FragTrap::FragTrap(FragTrap &src) : ClapTrap(src){
	*this = src;
	std::cout << "Copy Constructor of FragTrap called " << this->name_ << std::endl;
}

FragTrap::~FragTrap(){
	std::cout << "Destructor of FragTrap called" << std::endl;
}

FragTrap & FragTrap::operator=(FragTrap &assign){
	if (this != &assign){
		std::cout << "Assignment operator on " << assign.name_ << " called" << std::endl;
		this->name_ = assign.name_;
		this->hitPoints_ = assign.hitPoints_;
		this->energyPoints_ = assign.energyPoints_;
		this->attackDamage_ = assign.attackDamage_;
	}
	return (*this);
}

void FragTrap::attack(const std::string& target){
	if (this->energyPoints_ == 0)
		std::cout << this->name_ << " has no energy points and can not attack " << target << std::endl;
	else if (this->hitPoints_ == 0)
		std::cout << this->name_ << " has no hit points and can not attack " << target << std::endl;
	else {
		std::cout << this->name_ << " attacks " << target << " causing " << this->attackDamage_ << " points damage" << std::endl;
		this->energyPoints_--;
	}
}

void FragTrap::highFivesGuys(void){
	std::cout << this->name_ << " requests high five" << std::endl;
}
