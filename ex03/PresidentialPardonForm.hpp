#pragma once

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

class PresidentialPardonForm : public Form
{
	private:
		std::string _target;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
		void execute(Bureaucrat const & executor) const;
		~PresidentialPardonForm();
};