#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, unsigned int grade) : _name(name), _grade(grade)
{
	if (grade < 0)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	std::cout << _name << ", " <<_grade <<": Bureaucrat generate" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{
	std::cout << "Bureaucrat copy" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << std::endl;
	return (os);
}

const std::string& Bureaucrat::getName(void) const
{
	return (_name);
}

unsigned int Bureaucrat::getGrade(void) const
{
	return (_grade);
}

void Bureaucrat::increment(void)
{
	if (_grade == 1)
		throw GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrement(void)
{
	if (_grade == 150)
		throw GradeTooLowException();
	this->_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "grade high!\n";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "grade low!\n";
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << _name << ", " <<_grade << ": Bureaucrat delete" << std::endl;
}

void Bureaucrat::signForm(Form& form)
{
	if (form.getStatus() == true)
		std::cout << _name << " signed " << form.getName() << std::endl;
	else
		std::cout << _name << " couldn't sign " << form.getName() << "because out of range" << std::endl;
}