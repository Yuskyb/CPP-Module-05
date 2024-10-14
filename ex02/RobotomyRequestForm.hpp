#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;
		
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		void execute(Bureaucrat const & executor) const;
		~RobotomyRequestForm();
};