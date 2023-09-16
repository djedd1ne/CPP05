#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
					AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &obj) :
					AForm("RobotomyRequestForm", 72, 45) {
	*this = obj;
}

RobotomyRequestForm &RobotomyRequestForm::operator = (RobotomyRequestForm const &obj) {
	this->_target = obj.getTarget();
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {

	if (this->isSigned() == false)
		throw AForm::NotSignedException();
	else if (executor.getGrade() > this->getSignGrade())
		throw AForm::GradeTooLowException();
	else
	{
		srand(time(NULL));
		if (rand() % 2)
			std::cout << this->getTarget() << " is Robotomized !" << std::endl;
		else
			std::cout << this->getTarget() << " isn't Robotomized !" << std::endl;

	}
}

const std::string &RobotomyRequestForm::getTarget() const {
	return (this->_target);
}
