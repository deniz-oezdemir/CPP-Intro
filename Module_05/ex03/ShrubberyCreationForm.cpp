#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <fstream>
#include <string>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target_("none") {
	std::cout << "ShrubberyCreationForm constructor called (no target)" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), target_(target) {
	std::cout << "ShrubberyCreationForm constructor called (with target)" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &src) : AForm(src.getName(), src.getSignGrade(), src.getExecGrade()), target_(src.getTarget()) {
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm &assign) {
	std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
	this->target_ = assign.getTarget();
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm " << this->getName() << "'s destructor called" << std::endl;
}

std::string ShrubberyCreationForm::getTarget() const {
	return (this->target_);
}

void ShrubberyCreationForm::act(Bureaucrat const &executor) const {
	std::ofstream outFile((this->target_ + "_shrubbery").c_str());
	if (!outFile.is_open()) {
		std::cout << "Unable to create file" << std::endl;
		return ;
	}
	outFile << "       _-_\n";
	outFile << "    /~~   ~~\\\n";
	outFile << " /~~         ~~\\\n";
	outFile << "{               }\n";
	outFile << " \\  _-     -_  /\n";
	outFile << "   ~  \\\\ //  ~\n";
	outFile << "_- -   | | _- _\n";
	outFile << "  _ -  | |   -_\n";
	outFile << "      // \\\\\n";
	outFile.close();
	std::cout << "File "<< this->target_ + "_shrubbery" << " has been created by " << executor.getName() << std::endl;
}
