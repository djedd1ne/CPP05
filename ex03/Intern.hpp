#pragma once
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
	public:
		Intern();
		Intern(Intern const &obj);
		Intern &operator = (Intern const &obj);
		~Intern();

		AForm *makeForm(std::string name, std::string target);
};