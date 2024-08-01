#include "Bureaucrat.hpp"
#include "Forms.hpp"

Form::Form(): name_("anonymous"), isSigned_(false), requiredGradeSign_(1), requiredGradeExec_(1) {
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string name, unsigned int gradeSign, unsigned int gradeExec): name_(name), requiredGradeSign_(gradeSign), requiredGradeExec_(gradeExec) {
	std::cout << "Form constructor with grades called";
	if (gradeSign > 150 || gradeExec > 150) {
		std::cout << " but at least one grade is out of range:";
		throw(Form::GradeTooLowException());
	} else if (gradeSign < 1 || gradeExec < 1) {
		std::cout << " but at least one grade is out of range:";
		throw(Form::GradeTooHighException());
	} else
		this->isSigned_ = false;
	std::cout << std::endl;
}

Form::Form(Form &src): name_(src.getName()), isSigned_(src.isSigned_), requiredGradeSign_(src.requiredGradeSign_), requiredGradeExec_(src.requiredGradeExec_) {
	std::cout << "Form copy constructor called" << std::endl;
}

Form &Form::operator=(Form &assign) {
	std::cout << "Form copy assignment operator called" << std::endl;
	this->isSigned_ = assign.isSigned_;
	return (*this);
}

Form::~Form() {
	std::cout << "Form " << this->name_ << "'s destructor called" << std::endl;
}

const std::string	Form::getName() const {
	return (this->name_);
}

bool Form::getSignStatus() const {
	return (this->isSigned_);
}

unsigned int Form::getSignGrade() const {
	return (this->requiredGradeSign_);
}

unsigned int Form::getExecGrade() const {
	return (this->requiredGradeExec_);
}

const char *Form::GradeTooHighException::what() const throw() {
	return ("grade is too high");
}

const char *Form::GradeTooLowException::what() const throw() {
	return ("grade is too low");
}

void Form::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() <= this->getSignGrade())
		this->isSigned_ = true;
	else
		throw(Form::GradeTooLowException());
}

std::ostream &operator<<(std::ostream &str, const Form &form) {
	return (str << form.getName() << ", signed: " << form.getSignStatus() <<", sign grade " << form.getSignGrade() << ", execution grade " << form.getExecGrade() << ".");
}

