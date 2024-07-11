#include "ClapTrap.hpp"

// Constructors
ClapTrap::ClapTrap(): name_("Anonymous"), hitPoints_(10), energyPoints_(10), attackDamage_(0){
	std::cout << "Default Constructor of ClapTrap called: ClapTrap " << this->name_ << " created" << std::endl;
}

ClapTrap::ClapTrap(std::string name): name_(name), hitPoints_(10), energyPoints_(10), attackDamage_(0){
	std::cout << "Constructor of ClapTrap called: ClapTrap " << this->name_ << " created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy){
	std::cout << "Copy Constructor of ClapTrap called ClapTrap" << this->name_ << std::endl;
	*this = copy;
}

// Destructor
ClapTrap::~ClapTrap(){
	std::cout << "Destructor of ClapTrap called" << std::endl;
}

// Operator
ClapTrap & ClapTrap::operator=(const ClapTrap &assign)
{
	if (this != &assign){
		std::cout << "Assignment operator on ClapTrap " << assign.name_ << " called" << std::endl;
		this->name_ = assign.name_;
		this->hitPoints_ = assign.hitPoints_;
		this->energyPoints_ = assign.energyPoints_;
		this->attackDamage_ = assign.attackDamage_;
	}
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (this->energyPoints_ == 0)
		std::cout << "ClapTrap " << this->name_ << " has no energy points and can not attack " << target << std::endl;
	else if (this->hitPoints_ == 0)
		std::cout << "ClapTrap " << this->name_ << " has no hit points and can not attack " << target << std::endl;
	else {
		std::cout << "ClapTrap " << this->name_ << " attacks " << target << " causing " << this->attackDamage_ << " points damage" << std::endl;
		this->energyPoints_--;
	}
}

void ClapTrap::takeDamage(unsigned int amount){
	if (this->hitPoints_ == 0)
		std::cout << "ClapTrap " << this->name_ << " is dead and can not take further damage" << std::endl;
	else if (this->hitPoints_ <= amount){
		std::cout << "ClapTrap " << this->name_ << " took " << hitPoints_ << " damage and died" << std::endl;
		this->hitPoints_ = 0;
	} else {
		this->hitPoints_ -= amount;
		std::cout << "ClapTrap " << this->name_ << " took " << amount << " damage" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount){
	if (this->energyPoints_ == 0)
		std::cout << "ClapTrap " << this->name_ << " has no energy points and can not repair" << std::endl;
	else if (this->hitPoints_ == 0)
		std::cout << "ClapTrap " << this->name_ << " is dead and can not repair" << std::endl;
	else {
		this->hitPoints_ = this->hitPoints_ + amount;
		this->energyPoints_--;
		std::cout << "ClapTrap " << this->name_ << " spent 1 energy to repair and receives " << amount << " hit points" << std::endl;
	}
}
