#pragma once
#include "Bureaucrat.hpp"

class Form {
	private:
		const std::string _name;
		bool _is_signed;
		const int _grade_sign;
		const int _grade_execute;

		static const int _min = 150;
		static const int _max = 1;

	public:
		Form();
		Form(std::string name, int grade_sign, int grade_execute);
		Form(Form const &obj);
		Form &operator = (Form const &obj);
		~Form();

		const std::string &getName() const;
		int getSignGrade() const;
		int getExecuteGrade() const;
		bool isSigned() const;
		void beSigned(Bureaucrat &bureaucrat);

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
};

std::ostream    &operator<<(std::ostream &out, const Form &form);
