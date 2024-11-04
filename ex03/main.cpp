#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

int main()
{
	Intern intern("intern", 1);
	Bureaucrat bureaucrat("bureaucrat", 1);

	Form* form1 = intern.makeForm("shrubbery creation", "target1");
	form1->beSigned(bureaucrat);
	form1->execute(bureaucrat);
	delete form1;
}