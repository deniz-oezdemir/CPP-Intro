#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include <fstream>
#include <string>

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target_("none") {
	std::cout << "PresidentialPardonForm constructor called (no target)" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), target_(target) {
	std::cout << "PresidentialPardonForm constructor called (with target)" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &src) : AForm(src.getName(), src.getSignGrade(), src.getExecGrade()), target_(src.getTarget()) {
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm &assign) {
	std::cout << "PresidentialPardonForm copy assignment operator called" << std::endl;
	this->target_ = assign.getTarget();
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm " << this->getName() << "'s destructor called" << std::endl;
}

std::string PresidentialPardonForm::getTarget() const {
	return (this->target_);
}

void PresidentialPardonForm::act(Bureaucrat const &executor) const {
	std::cout << this->target_ << " has been pardoned by Zaphod Beeblebrox, executer was " << executor.getName() << std::endl;
}
