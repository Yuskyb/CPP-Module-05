#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat b("yu", 149);
		std::cout << b << std::endl;
		b.increment();
		std::cout <<b <<std::endl;
		b.increment();
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception caught" << e.what() << std::endl;
	}
	catch (...)
	{
		std::cerr << "Unkown exception caught" << std::endl;
	}
	return (0);
}