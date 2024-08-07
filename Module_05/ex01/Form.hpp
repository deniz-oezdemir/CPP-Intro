#pragma once
#include <iostream>
#include <string>

class Bureaucrat;

class Form {
	private:
		const std::string	name_;
		bool				isSigned_;
		const unsigned int	requiredGradeSign_;
		const unsigned int	requiredGradeExec_;

	public:
		Form();
		Form(std::string name, unsigned int gradeSign, unsigned int gradeExec);
		Form(Form &src);
		Form &operator=(Form &assign);

		~Form();

		const std::string	getName() const;
		bool				getSignStatus() const;
		unsigned int		getSignGrade() const;
		unsigned int		getExecGrade() const;

		void				beSigned(Bureaucrat &bureaucrat);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &str, const Form &form);
