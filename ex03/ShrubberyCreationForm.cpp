#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : 
			AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &obj) :
					AForm("ShrubberyCreationForm", 145, 137) {
		*this = obj;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator = (ShrubberyCreationForm const &obj) {
	this->_target = obj.getTarget();
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

const std::string &ShrubberyCreationForm::getTarget() const {
	return (this->_target);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (executor.getGrade() > this->getSignGrade())
		throw AForm::GradeTooLowException();
	else if (this->isSigned() == false)
		throw AForm::NotSignedException();
	else
	{
	std::ofstream file(this->_target + "_shrubbery");
	file << TREE << std::endl;
	file.close();
	}
}



