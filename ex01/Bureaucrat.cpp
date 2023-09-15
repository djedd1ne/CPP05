/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djmekki <djmekki@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 02:03:04 by djmekki           #+#    #+#             */
/*   Updated: 2023/09/12 02:03:04 by djmekki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string &name, int grade)
    : _name(name), _grade(grade){
        if (grade > 150)
            throw GradeTooLowException();
        else if (grade < 1)
            throw GradeTooHighException();
    }

Bureaucrat::Bureaucrat(const Bureaucrat& obj)
    :_name(obj._name), _grade(obj._grade) {}

Bureaucrat &Bureaucrat::operator= (const Bureaucrat& obj) {
    return *this;
}

const std::string& Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

void Bureaucrat::incGrade() {
    if (_grade-- <= 1)
        throw GradeTooHighException();
}

void Bureaucrat::decGrade() {
    if (_grade++ >= 150)
        throw GradeTooLowException();
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return "Grade is too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return "Grade is too low!";
}

std::ostream &operator << (std::ostream &out, const Bureaucrat &bureaucrat) {
    out << bureaucrat.getName() << " bureaucrat grade " <<
    bureaucrat.getGrade() << ".";
    return out;
}