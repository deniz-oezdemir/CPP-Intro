#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern() {
	std::cout << "Intern's default constructor called" << std::endl;
}

Intern::Intern(const Intern& src) {
	(void)src;
	std::cout << "Intern's copy constructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& assign) {
	(void)assign;
	std::cout << "Intern's assignment operator called" << std::endl;
	return (*this);
}

Intern::~Intern() {
	std::cout << "Intern's destructor called" << std::endl;
}

AForm *Intern::makeForm(std::string formName, std::string target) {
    AForm 		*(Intern::*functions[3])(std::string &) = {&Intern::makeSCF, &Intern::makeRRF, &Intern::makePPF};
	std::string	names[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};

	for (int i = 0; i < 3; i++) {
		if (formName == names[i]) {
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*functions[i])(target);
		}
	}
	throw(Intern::unknownForm());
}

const char *Intern::unknownForm::what() const throw() {
	return ("Form not found");
}

AForm *Intern::makeSCF(std::string &target) {
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeRRF(std::string &target) {
	return (new RobotomyRequestForm(target));
}

AForm *Intern::makePPF(std::string &target) {
	return (new PresidentialPardonForm(target));
}
