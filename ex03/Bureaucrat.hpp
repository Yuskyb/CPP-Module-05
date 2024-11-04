#pragma once

#include <iostream>
#include "Form.hpp"

class Bureaucrat {
	protected:
		std::string _name;
		unsigned int _grade;

	public:
		Bureaucrat(void);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat(const std::string& name, unsigned int grade);
		Bureaucrat& operator=(const Bureaucrat& other);
		const std::string& getName(void) const;
		unsigned int getGrade(void) const;
		void increment(void);
		void decrement(void);
		void executeForm(Form const & form) const;
		virtual ~Bureaucrat(void);
		class GradeTooHighException : public std::exception {
			const char * what() const throw();
		};
		void signForm(Form& form);

		class GradeTooLowException : public std::exception {
			const char *what() const throw();
		};
};

		std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);