#pragma once
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string _target;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const &obj);
		PresidentialPardonForm &operator = (PresidentialPardonForm const &obj);
		~PresidentialPardonForm();

		const std::string &getTarget() const;
		virtual void execute(Bureaucrat const &executor) const;
};