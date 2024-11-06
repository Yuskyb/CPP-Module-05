#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("default", 72, 45)
{
	std::cout << "RobotomyRequestForm generate" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : Form(target, 72, 45)
{
	std::cout << "RobotomyRequestForm generate" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : Form(other)
{
	std::cout << "RobotomyRequestForm copy" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this == &other)
		return (*this);
	Form::operator=(other);
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destroy" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	executor.executeForm(*this);
	std::cout << "wheen..." << std::endl;
	std::srand(static_cast<unsigned int>(time(0)));
	int i = std::rand() % 2;
	if (i == 0)
		std::cout << this->getName() << " has been robotomized successfully" << std::endl;
	else
		std::cout << this->getName() << " has not been robotomized" << std::endl;
}