#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"

class Intern 
{
	public:
	Intern();
	Intern(const Intern& other);
	~Intern();
	Intern& operator=(const Intern& other);

	AForm* makeForm(std::string name, std::string target);
};