#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("default", 72, 45)
{
	std::cout << "RobotomyRequestForm generate" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm(target, 72, 45)
{
	std::cout << "RobotomyRequestForm generate" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other)
{
	std::cout << "RobotomyRequestForm copy" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destroy" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	executor.executeForm(*this);
	std::cout << "wheen..." << std::endl;
	std::srand(static_cast<unsigned int>(std::time(0)));
	int i = std::rand() % 100;
	if (i >= 50)
		std::cout << this->getName() << " has been robotomized successfully" << std::endl;
	else
		std::cout << this->getName() << " has not been robotomized" << std::endl;
}