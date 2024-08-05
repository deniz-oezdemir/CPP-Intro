#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include <fstream>
#include <string>
#include <cstdlib> // srand, rand

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target_("none") {
	std::cout << "RobotomyRequestForm constructor called (no target)" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target_(target) {
	std::cout << "RobotomyRequestForm constructor called (with target)" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &src) : AForm(src.getName(), src.getSignGrade(), src.getExecGrade()), target_(src.getTarget()) {
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm &assign) {
	std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
	this->target_ = assign.getTarget();
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm " << this->getName() << "'s destructor called" << std::endl;
}

std::string RobotomyRequestForm::getTarget() const {
	return (this->target_);
}

void RobotomyRequestForm::act(Bureaucrat const &executor) const {
	std::cout << "Bzzzz... Bzzzz... Drilling noises..." << std::endl;
	srand(time(NULL)); //seeds random number generator with current time
	if (rand() % 2) { //checks whether random number is even number (true 50% of time)
		std::cout << this->target_ << " has been robotomized successfully by " << executor.getName() << std::endl;
	} else {
		std::cout << "The robotomy of " << this->target_ << " failed" << std::endl;
	}
}
