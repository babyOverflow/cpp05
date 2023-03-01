#include <iostream>
#include "PresidentialPardonForm.h"

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("PresidentialPardonForm", 72, 45), mTarget(target)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(other), mTarget(other.mTarget)
{

}

PresidentialPardonForm::~PresidentialPardonForm()
{}

void PresidentialPardonForm::excute(const Bureaucrat &excutor) const
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
		std::cout << "President, The Great, Zaphod Beeblebrox pardoned " + mTarget << std::endl;
	}
}