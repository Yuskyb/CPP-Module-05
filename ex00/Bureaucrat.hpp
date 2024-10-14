#pragma once

#include <iostream>

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
		virtual ~Bureaucrat(void);
		class GradeTooHighException : public std::exception {
			const char * what() const throw();
		};

		class GradeTooLowException : public std::exception {
			const char *what() const throw();
		};
};

		std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);