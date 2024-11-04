#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void)
		: _name("default"),
			_status(false),
			_grade_sign(150),
			_grade_execute(150)
{
	std::cout << _name << ": AForm generate" << std::endl;
}

AForm::AForm(const std::string& name,
				const unsigned int grade_sign,
				const unsigned int grade_execute)
				: _name(name),
					_status(false),
					_grade_sign(grade_sign),
					_grade_execute(grade_execute)
{
	std::cout << _name << ": AForm generate" << std::endl;
}

AForm::AForm(const AForm& other)
		: _name(other._name),
			_status(other._status),
			_grade_sign(other._grade_sign),
			_grade_execute(other._grade_execute)
{
	std::cout << "AForm copy" << std::endl;
}

AForm& AForm::operator=(const AForm& other)
{
	if (this == &other)
		return (*this);
	_status = other._status;
	return (*this);
}

const std::string& AForm::getName(void) const
{
	return (_name);
}

bool AForm::getStatus(void) const
{
	return (_status);
}

unsigned int AForm::getGradeSign(void) const
{
	return (_grade_sign);
}

unsigned int AForm::getGradeExecute(void) const
{
	return (_grade_execute);
}

void AForm::beSigned(Bureaucrat& b)
{
	if (b.getGrade() > _grade_sign)
		throw GradeTooLowException();
	_status = true;
	b.signForm(*this);
}

const char * AForm::GradeTooHighException::what() const throw()
{
	return ("grade too high!");
}

const char * AForm::GradeTooLowException::what() const throw()
{
	return ("grade too low!");
}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
	os << f.getName() << ": AForm grade status "
		<< f.getStatus() << ", AForm grade sign "
		<< f.getGradeSign() << ", AForm grade execute "
		<< f.getGradeExecute();
	return (os);
}

AForm::FormError::FormError(std::string message) : _message(message) {};

AForm::FormError::~FormError() throw() {};

const char* AForm::FormError::what() const throw()
{
	return (_message.c_str());
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (this->getStatus() == false)
		throw FormError("AForm is not signed");
	if (executor.getGrade() > this->_grade_execute)
		throw GradeTooLowException();
}

AForm::~AForm(void)
{
	std::cout << "AForm delete" << std::endl;
}
