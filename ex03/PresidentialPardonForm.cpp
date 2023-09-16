#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : 
					AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &obj) :
					AForm("PresidentialPardonForm", 25, 5)
{
	*this = obj;
}

PresidentialPardonForm &PresidentialPardonForm::operator = (PresidentialPardonForm const &obj) {
	this->_target = obj.getTarget();
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){}

const std::string &PresidentialPardonForm::getTarget() const {
	return (this->_target);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (this->isSigned() == false)
		throw AForm::NotSignedException();
	else if (executor.getGrade() > this->getSignGrade())
		throw AForm::GradeTooLowException();
	else
	{
		std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox" << std::endl;
	}
}

