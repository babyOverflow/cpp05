#include <exception>
#include <iostream>

#include "Bureaucrat.h"
#include "Form.h"

int main()
{
	std::cout << "============= From create =========== \n";
	Form form50("form50", 50);
	std::cout << form50 << std::endl;

	std::cout << "\n============= From sign =========== \n";
	try
	{
		Bureaucrat charlie("Charlie", Bureaucrat::HIGHEST_GRADE);
		std::cout << charlie << std::endl;
		charlie.signForm(form50);
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
		charlie.signForm(form50);
		charlie.demote();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
