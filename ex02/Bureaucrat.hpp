#pragma once

#include <iostream>
#include "AForm.hpp"

class Bureaucrat {
	private:
		const std::string _name;
		unsigned int _grade;

	public:
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat(const std::string& name, unsigned int grade);
		const std::string& getName(void) const;
		unsigned int getGrade(void) const;
		void increment(void);
		void decrement(void);
		void executeForm(AForm const & form) const;
		virtual ~Bureaucrat(void);
		class GradeTooHighException : public std::exception {
			const char * what() const throw();
		};
		void signForm(AForm& form);

		class GradeTooLowException : public std::exception {
			const char *what() const throw();
		};
};

		std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);