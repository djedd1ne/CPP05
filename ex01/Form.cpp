#include "Form.hpp"

Form::Form(): _name("default"), _is_signed(false), _grade_sign(150),
				_grade_execute(150) {}

Form::Form(std::string name, int grade_sign, int grade_execute) : _name(name),
	_grade_sign(grade_sign), _grade_execute(grade_execute), _is_signed(false) {
		if (grade_sign < _max || grade_execute < _max)
			throw Form::GradeTooHighException();
		else if (grade_sign > _min || grade_execute > _min)
			throw Form::GradeTooLowException();
}

Form::Form(Form const &obj) : _name(obj._name), _is_signed(obj._is_signed),
		_grade_sign(obj._grade_sign), _grade_execute(obj._grade_execute) {}

Form &Form::operator = (Form const &obj) {
	this->_is_signed = obj._is_signed;
	return (*this);
}

const std::string &Form::getName() const {
	return (this->_name);
}

int Form::getSignGrade() const {
	return (this->_grade_sign);
}

int Form::getExecuteGrade() const {
	return (this->_grade_execute);
}

bool Form::isSigned() const {
	return (this->_is_signed);
}

void Form::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() <= getSignGrade())
		this->_is_signed = true;
	bureaucrat.signForm(this->isSigned(), this->getName());
	if (bureaucrat.getGrade() > getSignGrade())
		throw Form::GradeTooLowException();
}

Form::~Form() {}

const char *Form::GradeTooHighException::what() const throw() {
  return "Grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw() {
  return "Grade is too low!";
}

std::ostream &operator << (std::ostream &out, const Form &form) {
	out << form.getName() << "'s grade " << form.getSignGrade() << " is";
	if (form.isSigned())
		out << " signed";
	else
		out << " not signed";
	return (out);
}
