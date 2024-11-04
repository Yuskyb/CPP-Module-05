#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

Intern::Intern(void) : Bureaucrat("default", 150)
{
	std::cout << "Intern generate" << std::endl;
}

Intern::Intern(const std::string& name, unsigned int grade) : Bureaucrat(name, grade)
{
	std::cout << "Intern generate" << std::endl;
}

Intern::Intern(const Intern& other) : Bureaucrat(other)
{
	std::cout << "Intern copy" << std::endl;
}

Intern& Intern::operator=(const Intern& other)
{
	if (this == &other)
		return (*this);
	Bureaucrat::operator=(other);
	return (*this);
}

Intern::~Intern(void)
{
	std::cout << "Intern destroy" << std::endl;
}

Form* Intern::makeForm(const std::string &name, const std::string &target)
{
	std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	int n = -1;
	for (int i = 0; i < 3; i++)
	{
		if (name == forms[i])
		{
			n = i;
			std::cout << "Intern creates " << name << std::endl;
			break;
		}
	}
	switch (n)
	{
		case 0:
			return (new ShrubberyCreationForm(target));
		case 1:
			return (new RobotomyRequestForm(target));
		case 2:
			return (new PresidentialPardonForm(target));
		default:
			std::cout << "Intern cannot creates" << std::endl;
			throw FormError();
			return (NULL);
	}
}

const char* Intern::FormError::what() const throw()
{
	return ("Form not found");
}