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

int main() {
	try {
			Bureaucrat test0("Default", 150);
			std::cout << test0 << std::endl;
	}
	catch (std::exception &e) {
			std::cout << e.what() << std::endl;
	}
    std::cout << std::string(40, '*') << std::endl;

    Bureaucrat test0("First", 2);
    try {
			test0.incGrade();
			std::cout << test0 << std::endl;
            test0.incGrade();
			std::cout << test0 << std::endl;
            test0.incGrade();
			std::cout << test0 << std::endl;       
	}
	catch (std::exception &e) {
			std::cout << e.what() << std::endl;
	}

    std::cout << std::string(40, '*') << std::endl;
    Bureaucrat test1("Second", 149);
    try {
			test1.decGrade();
			std::cout << test1 << std::endl;
            test1.decGrade();
			std::cout << test1 << std::endl;
            test1.decGrade();
			std::cout << test1 << std::endl;       
	}
	catch (std::exception &e) {
			std::cout << e.what() << std::endl;
	}
    return (0);
}