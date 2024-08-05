#pragma once
#include <iostream>
#include <string>
class Form;

class Bureaucrat {
	private:
		const std::string	name_;
		unsigned int		grade_;

	public:
		Bureaucrat();
		Bureaucrat(std::string const name);
		Bureaucrat(Bureaucrat &src);
		Bureaucrat &operator=(Bureaucrat &assign);

		Bureaucrat(unsigned int grade);
		Bureaucrat(std::string const name, unsigned int grade);

		~Bureaucrat();

		const std::string	getName();
		unsigned int		getGrade();

		void				incrementGrade();
		void				decrementGrade();
		void				signForm(Form &form);

		// Custom exception classes inherit from standard std::exception class and handle error cases
		class GradeTooHighException : public std::exception	{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &str, Bureaucrat &bureaucrat);
