#include "AForm.hpp"

AForm::AForm(): _name("default"), _is_signed(false), _grade_sign(150),
				_grade_execute(150) {}

AForm::AForm(std::string name, int grade_sign, int grade_execute) : _name(name),
	_grade_sign(grade_sign), _grade_execute(grade_execute), _is_signed(false) {
		if (grade_sign < _max || grade_execute < _max)
			throw AForm::GradeTooHighException();
		else if (grade_sign > _min || grade_execute > _min)
			throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const &obj) : _name(obj._name), _is_signed(obj._is_signed),
		_grade_sign(obj._grade_sign), _grade_execute(obj._grade_execute) {}

AForm &AForm::operator = (AForm const &obj) {
	this->_is_signed = obj._is_signed;
	return (*this);
}

const std::string &AForm::getName() const {
	return (this->_name);
}

int AForm::getSignGrade() const {
	return (this->_grade_sign);
}

int AForm::getExecuteGrade() const {
	return (this->_grade_execute);
}

bool AForm::isSigned() const {
	return (this->_is_signed);
}

void AForm::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() <= getSignGrade())
		this->_is_signed = true;
	bureaucrat.signForm(this->isSigned(), this->getName());
	if (bureaucrat.getGrade() > getSignGrade())
		throw AForm::GradeTooLowException();
}

AForm::~AForm() {}

const char *AForm::GradeTooHighException::what() const throw() {
  return "Grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw() {
  return "Grade is too low!";
}

const char *AForm::NotSignedException::what() const throw() {
  return "Must be signed first!";
}

std::ostream &operator << (std::ostream &out, const AForm &form) {
	out << form.getName() << "'s grade " << form.getSignGrade() << " is";
	if (form.isSigned())
		out << " signed";
	else
		out << " not signed";
	return (out);
}
