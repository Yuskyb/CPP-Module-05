#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("default", 25, 5)
{
	std::cout << "PresidentialPardonForm generate" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : Form(target, 25, 5)
{
	std::cout << "PresidentialPardonForm generate" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : Form(other)
{
	std::cout << "PresidentialPardonForm copy" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this == &other)
		return (*this);
	Form::operator=(other);
	return (*this);
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