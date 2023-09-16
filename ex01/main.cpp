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
#include "Form.hpp"

int main() {
	std::string line (30, '*');

	{
		try {
			Form form00("FORM 10", 0, 10);
			std::cout << form00 << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << line << std::endl;
	{
		try {
			Bureaucrat djmekki("djmekki", 5);
			Form form00("A00", 20, 5);
			std::cout << djmekki << std::endl;
			std::cout << form00 << std::endl;
			form00.beSigned(djmekki);
			std::cout << form00 << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << line << std::endl;
	{
		try {
			Bureaucrat mekki("mekki", 150);
			Form form00("A00", 20, 5);
			std::cout << mekki << std::endl;
			std::cout << form00 << std::endl;
			form00.beSigned(mekki);
			std::cout << form00 << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
    return (0);
}