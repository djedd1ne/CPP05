#pragma once
#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;
	
	public:
		ShrubberyCreationForm();
    	ShrubberyCreationForm(std::string target);
   		ShrubberyCreationForm(ShrubberyCreationForm const &obj);
		ShrubberyCreationForm& operator = (const ShrubberyCreationForm &obj);
		~ShrubberyCreationForm();

		const std::string &getTarget() const;
		virtual void execute(Bureaucrat const &executor) const;
};

#define TREE "              v .   ._, |_  .," << std::endl \
<<"           `-._\\/  .  \\ /    |/_" << std::endl \
<<"               \\  _\\, y | \\// " << std::endl \
<<"         _\\_.___\\, \\/ -.\\||" << std::endl \
<<"          `7-,--.`._||  / / ," << std::endl \
<<"           /'     `-. `./ / |/_.\'" << std::endl \
<<"                     |    |//" << std::endl \
<<"                     |_    /" << std::endl \
<<"                     |-   |" << std::endl \
<<"                     |   =|" << std::endl \
<<"                     |    |" << std::endl \
<<"--------------------/ ,  . \\--------._"