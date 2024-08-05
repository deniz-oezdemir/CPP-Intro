#pragma once
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class PresidentialPardonForm : public AForm {
	private:
		std::string	target_;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm &src);
		PresidentialPardonForm &operator=(PresidentialPardonForm &assign);
		~PresidentialPardonForm();

		std::string getTarget() const;
		void act(Bureaucrat const &executor) const;
};
