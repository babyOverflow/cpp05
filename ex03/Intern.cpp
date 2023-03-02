#include <iostream>
#include "Intern.h"

Intern::Intern()
{

}

Intern::~Intern()
{

}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern& Intern::operator=(const Intern &other)
{
	(void)other;
	return *this;
}

AForm* makeShru(std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm* makeRobo(std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm* makePardon(std::string target)
{
	return new PresidentialPardonForm(target);
}

struct Ex03
{
	AForm* (*maker)(std::string);
	std::string name;
};

AForm* Intern::makeForm(std::string name, std::string target)
{
	Ex03 makers[] = {
		{makeShru, "shruberry creation"},
		{makeRobo, "robotomy request"},
		{makePardon, "presidential pardon"}
	};

	for (int i = 0; i < 3; ++i)
	{
		if (makers[i].name == name)
			return makers[i].maker(target);
	}

	throw NotFoundForm();
}

const char* Intern::NotFoundForm::what() const throw()
{
	return "Not found form";
}
