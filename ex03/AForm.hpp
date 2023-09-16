#pragma once
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		const std::string _name;
		bool _is_signed;
		const int _grade_sign;
		const int _grade_execute;

		static const int _min = 150;
		static const int _max = 1;

	public:
		AForm();
		AForm(std::string name, int grade_sign, int grade_execute);
		AForm(AForm const &obj);
		AForm &operator = (AForm const &obj);
		~AForm();

		const std::string &getName() const;
		int getSignGrade() const;
		int getExecuteGrade() const;
		bool isSigned() const;
		void beSigned(Bureaucrat &bureaucrat);
		virtual void execute(Bureaucrat const &executor) const = 0;

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class NotSignedException: public std::exception 
		{
			public:
				const char* what() const throw();
		};

};

std::ostream    &operator<<(std::ostream &out, const AForm &form);
