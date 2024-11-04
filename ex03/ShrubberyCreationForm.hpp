#pragma once

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

class ShrubberyCreationForm : public Form
{
	private:
		std::string _target;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		void execute(Bureaucrat const & executor) const;
		~ShrubberyCreationForm();
};