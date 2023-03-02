#include <exception>
#include <iostream>

#include "Bureaucrat.h"
#include "Intern.h"

int main()
{
	std::cout << "============= From create =========== \n";

	Intern intern;
	AForm* formShru = intern.makeForm("shruberry creation", "formShru");

	std::cout << "\n============= Shru From =========== \n";
	try
	{
		Bureaucrat charlie("Charlie", Bureaucrat::HIGHEST_GRADE);
		std::cout << charlie << std::endl;
		charlie.executeForm(*formShru);
		charlie.signForm(*formShru);
		formShru->excute(charlie);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}


}
