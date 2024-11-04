#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void)
		: _name("default"),
			_status(false),
			_grade_sign(150),
			_grade_execute(150)
{
	std::cout << _name << ": Form generate" << std::endl;
}

Form::Form(const std::string& name,
				const unsigned int grade_sign,
				const unsigned int grade_execute)
				: _name(name),
					_status(false),
					_grade_sign(grade_sign),
					_grade_execute(grade_execute)
{
	std::cout << _name << ": Form generate" << std::endl;
}

Form::Form(const Form& other)
		: _name(other._name),
			_status(other._status),
			_grade_sign(other._grade_sign),
			_grade_execute(other._grade_execute)
{
	std::cout << "Form copy" << std::endl;
}

Form& Form::operator=(const Form& other)
{
	if (this == &other)
		return (*this);
	_status = other._status;
	return (*this);
}

const std::string& Form::getName(void) const
{
	return (_name);
}

bool Form::getStatus(void) const
{
	return (_status);
}

unsigned int Form::getGradeSign(void) const
{
	return (_grade_sign);
}

unsigned int Form::getGradeExecute(void) const
{
	return (_grade_execute);
}

void Form::beSigned(Bureaucrat& b)
{
	if (b.getGrade() > _grade_sign)
		throw GradeTooLowException();
	b.signForm(*this);
	_status = true;
}

const char * Form::GradeTooHighException::what() const throw()
{
	return ("grade too high!");
}

const char * Form::GradeTooLowException::what() const throw()
{
	return ("grade too low!");
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
	os << f.getName() << ": Form grade status "
		<< f.getStatus() << ", Form grade sign "
		<< f.getGradeSign() << ", Form grade execute "
		<< f.getGradeExecute();
	return (os);
}

Form::~Form(void)
{
	std::cout << "Form delete" << std::endl;
}
