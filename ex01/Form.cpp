#include "Form.h"

Form::Form(std::string name, int grade)
	:mName(name), mIsSigned(false), mGradeToSign(grade), mGradeToExcute(grade)
{
	if (grade < HIGHEST_GRADE)
		throw GradeTooHighException();
	else if (grade > LOWEST_GRADE)
		throw GradeTooLowException();
}

Form::Form(const Form& other)
	:mName(other.getName()),
	mIsSigned(other.mIsSigned),
	mGradeToSign(other.mGradeToSign),
	mGradeToExcute(other.mGradeToExcute)
{
}

Form::~Form()
{}

void Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() <= mGradeToSign)
		mIsSigned = true;
	else
		throw GradeTooLowException();
}

std::string Form::getName() const
{
	return mName;
}
