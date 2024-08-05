#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm(): name_("anonymous"), isSigned_(false), requiredGradeSign_(1), requiredGradeExec_(1) {
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(std::string name, unsigned int gradeSign, unsigned int gradeExec): name_(name), requiredGradeSign_(gradeSign), requiredGradeExec_(gradeExec) {
	std::cout << "AForm constructor with grades called";
	if (gradeSign > 150 || gradeExec > 150) {
		std::cout << " but at least one grade is out of range:";
		throw(AForm::GradeTooLowException());
	} else if (gradeSign < 1 || gradeExec < 1) {
		std::cout << " but at least one grade is out of range:";
		throw(AForm::GradeTooHighException());
	} else
		this->isSigned_ = false;
	std::cout << std::endl;
}

AForm::AForm(AForm &src): name_(src.getName()), isSigned_(src.isSigned_), requiredGradeSign_(src.requiredGradeSign_), requiredGradeExec_(src.requiredGradeExec_) {
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm &AForm::operator=(AForm &assign) {
	std::cout << "AForm copy assignment operator called" << std::endl;
	this->isSigned_ = assign.isSigned_;
	return (*this);
}

AForm::~AForm() {
	std::cout << "AForm " << this->name_ << "'s destructor called" << std::endl;
}

const std::string	AForm::getName() const {
	return (this->name_);
}

bool AForm::getSignStatus() const {
	return (this->isSigned_);
}

unsigned int AForm::getSignGrade() const {
	return (this->requiredGradeSign_);
}

unsigned int AForm::getExecGrade() const {
	return (this->requiredGradeExec_);
}

const char *AForm::GradeTooHighException::what() const throw() {
	return ("grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw() {
	return ("grade is too low");
}

const char *AForm::NotSignedException::what() const throw() {
	return ("form is not signed");
}

void AForm::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() <= this->getSignGrade())
		this->isSigned_ = true;
	else
		throw(AForm::GradeTooLowException());
}

void AForm::execute(Bureaucrat const &executor) const {
	if (this->getSignStatus() == false)
		throw(AForm::NotSignedException());
	if (executor.getGrade() > this->getExecGrade())
		throw(AForm::GradeTooLowException());
	this->act(executor);
}

std::ostream &operator<<(std::ostream &str, const AForm &form) {
	return (str << form.getName() << ", signed: " << form.getSignStatus() <<", sign grade " << form.getSignGrade() << ", execution grade " << form.getExecGrade() << ".");
}

