#include "Bureaucrat.hpp"
#include "Form.hpp"

// Constructors

Bureaucrat::Bureaucrat(): name_("anonymous"), grade_(150) {
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name): name_(name), grade_(150) {
	std::cout << "Bureaucrat " << name << "'s constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat &src): name_(src.getName()), grade_(src.getGrade()) {
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat &assign) {
	std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	this->grade_ = assign.grade_;
	return (*this);
}

Bureaucrat::Bureaucrat(unsigned int grade): name_("anonymous") {
	std::cout << "Bureaucrat constructor with grade called";
	if (grade > 150) {
		std::cout << " but grade is out of range:";
		throw(GradeTooLowException());
	} else if (grade < 1) {
		std::cout << " but grade is out of range:";
		throw(GradeTooHighException());
	} else
		this->grade_ = grade;
	std::cout << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, unsigned int grade): name_(name) {
	std::cout << "Bureaucrat " << name << "'s constructor with grade called";
	if (grade > 150) {
		std::cout << " but grade is out of range:";
		throw(GradeTooLowException());
	} else if (grade < 1) {
		std::cout << " but grade is out of range:";
		throw(GradeTooHighException());
	} else
		this->grade_ = grade;
	std::cout << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat " << this->name_ << "'s destructor called" << std::endl;
}

const std::string Bureaucrat::getName() {
	return (this->name_);
}

unsigned int Bureaucrat::getGrade() {
	return (this->grade_);
}

void Bureaucrat::incrementGrade() {
	if (grade_ == 1)
		throw(GradeTooHighException());
	else
		grade_--;
}

void Bureaucrat::decrementGrade() {
	if (grade_ == 150)
		throw(GradeTooLowException());
	else
		grade_++;
}

void Bureaucrat::signForm(Form &form) {
	try	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e) {
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << "." << std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade can not be higher than 1");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade can not be lower than 150");
}

std::ostream &operator<<(std::ostream &str, Bureaucrat &bureaucrat) {
	return (str << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".");
}
