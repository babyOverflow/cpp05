#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"
#include <exception>

class Intern 
{
	public:
	Intern();
	Intern(const Intern& other);
	~Intern();
	Intern& operator=(const Intern& other);

	AForm* makeForm(std::string name, std::string target);

class NotFoundForm: std::exception
{
	public:
	const char * what() const throw();
};
};