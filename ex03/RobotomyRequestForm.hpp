#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	private:
		std::string _target;
	
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const &obj);
		RobotomyRequestForm &operator = (RobotomyRequestForm const &obj);
		~RobotomyRequestForm();

		const std::string &getTarget() const;
		virtual void execute(Bureaucrat const &executor) const;
};