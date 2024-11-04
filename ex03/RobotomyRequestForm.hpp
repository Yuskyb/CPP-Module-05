#pragma once

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

class RobotomyRequestForm : public Form
{
	private:
		std::string _target;
		
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		void execute(Bureaucrat const & executor) const;
		~RobotomyRequestForm();
};