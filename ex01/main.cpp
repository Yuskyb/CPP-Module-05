#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Form f("form", 5, 3);
		Bureaucrat b("yu", 5);
		f.beSigned(b);
		b.increment();
		b.increment();
		std::cout << f << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	return (0);
}