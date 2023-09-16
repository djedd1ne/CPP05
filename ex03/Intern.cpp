#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(Intern const &obj) {
	*this = obj;
}

Intern &Intern::operator = (Intern const &obj) {
	return (*this);
}

Intern::~Intern() {}

AForm *Intern::makeForm(std::string name, std::string target) {
	std::string array[3] = {"shrubbery", "robotomy", "presidential"};
	AForm		*forms[3] = {new RobotomyRequestForm(target), new PresidentialPardonForm(target), new ShrubberyCreationForm(target)};

	for(int i = 0; i < 3; i++)
	{
		if (name == array[i])
		{
			std::cout << "Intern creates " << array[i] << std::endl;
			return (forms[i]);
		}
	}
	std::cout << name << ": this form doesn't exist" << std::endl;
	return (NULL);
}