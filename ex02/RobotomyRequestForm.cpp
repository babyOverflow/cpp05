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
		std::cout << "Drilllllll~~" << std::endl;
		if (std::rand() % 2)
		{
			std::cout << "Success to robotomized " << mTarget << ", successed " << ++count << "times" << std::endl;
		}
		else
		{
		
			std::cout << "Fail" << std::endl;
		}
	}
}