#pragma once
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class RobotomyRequestForm : public AForm {
	private:
		std::string	target_;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm &src);
		RobotomyRequestForm &operator=(RobotomyRequestForm &assign);
		~RobotomyRequestForm();

		std::string getTarget() const;
		void act(Bureaucrat const &executor) const;
};
