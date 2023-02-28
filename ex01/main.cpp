#include <exception>
#include <iostream>
#include "Bureaucrat.h"

int main()
{
	try
	{
		Bureaucrat charlie("Charlie", Bureaucrat::HIGHEST_GRADE);
		std::cout << charlie << std::endl;
		charlie.promote();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat charlie("Charlie", Bureaucrat::LOWEST_GRADE);
		std::cout << charlie << std::endl;
		charlie.demote();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
