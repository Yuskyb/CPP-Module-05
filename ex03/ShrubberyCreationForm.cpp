#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137) , _target("default")
{
	std::cout << "ShrubberyCreationForm generate" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : Form(target, 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm generate" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : Form(other)
{
	std::cout << "ShrubberyCreationForm copy" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this == &other)
		return (*this);
	Form::operator=(other);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm delete" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	executor.executeForm(*this);
	std::ofstream file((this->_target + "_shrubbery").c_str());
	if (!file)
		throw FormError("File could not be opened");
	file << "       _-_\n";
	file << "    /~~   ~~\\\n";
	file << " /~~         ~~\\\n";
	file << "{               }\n";
	file << " \\  _-     -_  /\n";
	file << "   ~  \\ //  ~\n";
	file << "_- -   | | _- _\n";
	file << "  _ -  | |   -_\n";
	file << "      // \\\n";
	file << "     //   \\\n";
	file << "    //     \\\n";
	file << "   ~~       ~~\n";
	file.close();
}
