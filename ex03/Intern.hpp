#pragma once

#include "Bureaucrat.hpp"
#include "Form.hpp"

class Intern : virtual public Bureaucrat
{
	public:
		Intern(void);
		Intern(const Intern& other);
		Intern(const std::string& name, unsigned int grade);
		Intern& operator=(const Intern& other);
		virtual ~Intern(void);
		Form* makeForm(const std::string &name, const std::string &target);
		class FormError : public std::exception {
			const char *what() const throw();
		};
};