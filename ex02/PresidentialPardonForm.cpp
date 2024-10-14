#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("default", 25, 5)
{
	std::cout << "PresidentialPardonForm generate" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm(target, 25, 5)
{
	std::cout << "PresidentialPardonForm generate" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other)
{
	std::cout << "PresidentialPardonForm copy" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destroy" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	executor.executeForm(*this);
	std::cout << this->getName() << " has been pardoned by Zafod Beeblebrox" << std::endl;
}