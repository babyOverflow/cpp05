#include "ShrubberyCreationForm.h"
#include "AForm.h"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("ShrubberyCreationForm", 145, 137), mTarget(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), mTarget(other.mTarget)
{

}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

void ShrubberyCreationForm::excute(const Bureaucrat &excutor) const
{
	if (!isSigned())
	{
		throw ExecuteUnsignedForm();
	}
	else if (excutor.getGrade() > getGradeToExcute())
	{
		throw GradeTooLowException();
	}
	else
	{
		std::string fileName = mTarget + "_shrubbery";
		std::ofstream file;
		file.open(fileName);
		if (file.is_open())
		{
			file <<  "       _-_\n";
			file <<  "    /~~   ~~\\\n";
			file <<  " /~~         ~~\\\n";
			file <<  "{               }\n";
			file <<  " \\  _-     -_  /\n";
			file <<  "   ~  \\\\ //  ~\n";
			file <<  "_- -   | | _- _\n";
			file <<  "  _ -  | |   -_\n";
			file <<  "      // \\\\\n";
		}
		else {
			std::cout << "Failed to open " << fileName << std::endl;
		}
	}
}