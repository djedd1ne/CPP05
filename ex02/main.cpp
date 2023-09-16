/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djmekki <djmekki@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 08:19:27 by djmekki           #+#    #+#             */
/*   Updated: 2023/09/13 08:19:27 by djmekki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main() {
	std::string line (30, '*');

	ShrubberyCreationForm shrubbery("London");
	RobotomyRequestForm robotomy("Robocap");
	Bureaucrat djmekki("djmekki", 1);
	Bureaucrat sergiu("Sergiu", 2);
	
	{
		try {
			std::cout << djmekki << std::endl;
			std::cout << shrubbery << std::endl;
			shrubbery.beSigned(djmekki);
			sergiu.executeForm(shrubbery);
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << line << std::endl;
	{
		try{
			std::cout << djmekki << std::endl;
			std::cout << robotomy << std::endl;
			robotomy.beSigned(sergiu);
			sergiu.executeForm(robotomy);
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
    return (0);
}