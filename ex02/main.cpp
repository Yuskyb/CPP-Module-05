#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Bureaucrat bob("Bob", 1);
		Bureaucrat jim("Jim", 150);
		Bureaucrat tom("Tom", 75);

		ShrubberyCreationForm shrubbery("home");
		RobotomyRequestForm robotomy("robot");
		PresidentialPardonForm presidential("president");

		std::cout << shrubbery << std::endl;
		shrubbery.beSigned(bob);
		shrubbery.execute(bob);

		std::cout << robotomy << std::endl;
		robotomy.beSigned(bob);
		robotomy.execute(bob);

		std::cout << presidential << std::endl;
		presidential.beSigned(bob);
		presidential.execute(bob);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(...)
	{
		std::cerr << "Error" << std::endl;
	}
	return (0);
}