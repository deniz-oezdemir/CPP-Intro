#pragma once
#include <iostream>
#include <string>

class Bureaucrat;

class AForm {
	private:
		const std::string	name_;
		bool				isSigned_;
		const unsigned int	requiredGradeSign_;
		const unsigned int	requiredGradeExec_;

	public:
		AForm();
		AForm(std::string name, unsigned int gradeSign, unsigned int gradeExec);
		AForm(AForm &src);
		AForm &operator=(AForm &assign);

		virtual ~AForm();

		const std::string	getName() const;
		bool				getSignStatus() const;
		unsigned int		getSignGrade() const;
		unsigned int		getExecGrade() const;
		virtual std::string	getTarget() const = 0; // ex02

		void				beSigned(Bureaucrat &bureaucrat);
		virtual void		execute(Bureaucrat const &executor) const; // ex02 // checks signature and grade - in this base class
		virtual void		act(Bureaucrat const &executor) const = 0; // ex02 // executes the action - in the derived classes

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class NotSignedException : public std::exception {
			public:
				virtual const char	*what() const throw();
		}; // ex02

};

std::ostream	&operator<<(std::ostream &str, const AForm &form);
