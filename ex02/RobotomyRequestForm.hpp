#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <cmath>
#include <cstdlib>


class RobotomyRequestForm : public AForm
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