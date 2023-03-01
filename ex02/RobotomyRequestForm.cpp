#include <cstdlib>
#include <iostream>
#include <ctime>

#include "RobotomyRequestForm.h"


RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("RobotomyRequestForm", 72, 45), mTarget(target)
{

		std::srand(std::time(0));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other), mTarget(other.mTarget)
{

		std::srand(std::time(0));
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

void RobotomyRequestForm::excute(const Bureaucrat &excutor) const
{
	static int count = 0;
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
		float f = static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX);
		if (f < 0.5)
		{
			std::cout << "Drilllllll~~" << ++count << std::endl;
		}
	}
}