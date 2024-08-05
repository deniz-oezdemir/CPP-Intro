#pragma once
#include "AForm.hpp"

class Intern {
	public:
		Intern();
		Intern(const Intern& src);
		Intern& operator=(const Intern& assign);

		~Intern();

		AForm *makeForm(std::string name, std::string target);
		AForm *makeSCF(std::string &target);
		AForm *makeRRF(std::string &target);
		AForm *makePPF(std::string &target);

		class unknownForm : public std::exception {
			public:
				virtual const char	*what() const throw();
		};
};
