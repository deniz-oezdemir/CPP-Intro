#pragma once
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class ShrubberyCreationForm : public AForm {
	private:
		std::string	target_;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm &src);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm &assign);
		~ShrubberyCreationForm();

		std::string getTarget() const;
		void act(Bureaucrat const &executor) const;
};
