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
		std::cout << this->name_ << ", " << this->name_ << ", has no energy points, sir " << this->name_ << " cannot attack, no sir" << std::endl;
	else if (this->hitPoints_ == 0)
		std::cout << this->name_ << ", " << this->name_ << ", has no hit points, sir " << this->name_ << " cannot attack, " << this->name_ << " is too weak, sir." << std::endl;
	else {
		std::cout << this->name_ << ", attacks " << target << ", sir, causing " << this->attackDamage_ << " damage, sir" << std::endl;
		this->energyPoints_--;
	}
}

void FragTrap::highFivesGuys(void){
	std::cout << this->name_ << ": who wants a high five?!" << std::endl;
}
