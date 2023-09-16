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
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"


int main() {
	std::string line (30, '*');
	Bureaucrat djmekki("djmekki", 1);
	Intern intern;
	AForm	*form00 = intern.makeForm("robotomy", "target00");
	AForm	*form01 = intern.makeForm("presidential", "target01");
	AForm	*form02 = intern.makeForm("shrubbery", "target02");
	AForm	*form03 = intern.makeForm("random", "random_target");

    return (0);
}