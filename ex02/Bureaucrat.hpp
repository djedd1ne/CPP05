/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djmekki <djmekki@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 02:02:10 by djmekki           #+#    #+#             */
/*   Updated: 2023/09/12 02:02:10 by djmekki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
#include "AForm.hpp"

class AForm;

class Bureaucrat {
    private:
        std::string const _name;
        int _grade;
        static const int _min = 150;
        static const int _max = 1;
    public:
        Bureaucrat();
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(Bureaucrat const &obj);
        Bureaucrat &operator = (Bureaucrat const &obj);

        const std::string &getName() const;
        int getGrade() const;
        void incGrade();
        void decGrade();
        void signForm(bool is_signed, const std::string form_name);
        void executeForm(AForm const &form);

        class GradeTooHighException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
};

std::ostream &operator << (std::ostream &out, const Bureaucrat &bureaucrat);