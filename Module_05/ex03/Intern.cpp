#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

AForm *makeSCF(std::string target);
AForm *makeRRF(std::string target);
AForm *makePPF(std::string target);

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

AForm *Intern::makeForm(std::string formName, std::string target)
{
	AForm			*(*functions[3])(const std::string target) = {&makeSCF, &makeRRF, &makePPF};
	std::string		names[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};

	for (int i = 0; i < 3; i++) {
		if (formName == names[i]) {
			std::cout << "Intern creates " << formName << std::endl;
			return (functions[i](target));
		}
	}
	throw(Intern::unknownForm());
}

const char *Intern::unknownForm::what() const throw() {
	return ("Form with given name does not exist");
}

AForm *makeSCF(std::string target) {
	return (new ShrubberyCreationForm(target));
}

AForm *makeRRF(std::string target) {
	return (new RobotomyRequestForm(target));
}

AForm *makePPF(std::string target) {
	return (new PresidentialPardonForm(target));
}
