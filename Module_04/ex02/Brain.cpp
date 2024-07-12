#include "Brain.hpp"

Brain::Brain(){
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &src){
	std::cout << "Brain copy constructor called" << std::endl;
	*this = src;
}

Brain	&Brain::operator=(const Brain &assign){
	std::cout << "Brain copy assignment operator called" << std::endl;
	std::copy(assign.ideas, assign.ideas + 100, this->ideas);
	return (*this);
}

Brain::~Brain(){
	std::cout << "Brain destructor called" << std::endl;
}
