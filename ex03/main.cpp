#include <exception>
#include <iostream>

#include "Bureaucrat.h"
#include "Intern.h"

int main()
{
	std::cout << "============= From create err =========== \n";

	Intern intern;
	try
	{
		AForm* formDum = intern.makeForm("s creation", "form");
		Bureaucrat charlie("Charlie", Bureaucrat::HIGHEST_GRADE);
		std::cout << charlie << std::endl;
		charlie.executeForm(*formDum);
		charlie.signForm(*formDum);
		charlie.executeForm(*formDum);
	}
	catch (Intern::NotFoundForm& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n============= Shru From =========== \n";
	try
	{
		AForm* formShru = intern.makeForm("shruberry creation", "formShru");
		Bureaucrat charlie("Charlie", Bureaucrat::HIGHEST_GRADE);
		std::cout << charlie << std::endl;
		charlie.executeForm(*formShru);
		charlie.signForm(*formShru);
		formShru->excute(charlie);
		delete formShru;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

}
