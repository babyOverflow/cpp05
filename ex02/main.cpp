#include <exception>
#include <iostream>

#include "Bureaucrat.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"

int main()
{
	std::cout << "============= From create =========== \n";
	ShrubberyCreationForm formShru("formShru");
	std::cout << formShru << std::endl;

	RobotomyRequestForm formRobo("formRobo");
	std::cout << formRobo << std::endl;

	PresidentialPardonForm formPardon("formPardon");
	std::cout << formPardon << std::endl;


	std::cout << "\n============= Shru From =========== \n";
	try
	{
		Bureaucrat charlie("Charlie", Bureaucrat::HIGHEST_GRADE);
		std::cout << charlie << std::endl;
		charlie.executeForm(formShru);
		charlie.signForm(formShru);
		formShru.excute(charlie);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n============= Robo From =========== \n";
	try
	{
		Bureaucrat charlie("Charlie", Bureaucrat::HIGHEST_GRADE);
		std::cout << charlie << std::endl;
		charlie.signForm(formRobo);
		for (int i = 0; i < 100; ++i)
			formRobo.excute(charlie);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n============= Pardon From =========== \n";
	try
	{
		Bureaucrat charlie("Charlie", Bureaucrat::HIGHEST_GRADE);
		std::cout << charlie << std::endl;
		charlie.signForm(formPardon);
		formPardon.excute(charlie);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

}
