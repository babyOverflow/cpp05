#include "AForm.h"

AForm::AForm(std::string name, int grade)
	:mName(name), mIsSigned(false), mGradeToSign(grade), mGradeToExcute(grade)
{
	if (grade < HIGHEST_GRADE)
		throw GradeTooHighException();
	else if (grade > LOWEST_GRADE)
		throw GradeTooLowException();
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExcute)
	:mName(name),
	mIsSigned(false),
	mGradeToSign(gradeToSign),
	mGradeToExcute(gradeToExcute)
{
	if (gradeToSign < HIGHEST_GRADE)
		throw GradeTooHighException();
	else if (gradeToSign > LOWEST_GRADE)
		throw GradeTooLowException();
	else if (gradeToExcute < HIGHEST_GRADE)
		throw GradeTooHighException();
	else if (gradeToExcute > LOWEST_GRADE)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
	:mName(other.getName()),
	mIsSigned(other.mIsSigned),
	mGradeToSign(other.mGradeToSign),
	mGradeToExcute(other.mGradeToExcute)
{
}

AForm::~AForm()
{}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "AForm grade too high exception";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "AForm grade too low exception";
}

const char* AForm::ExecuteUnsignedForm::what() const throw()
{
	return "AForm grade too low exception";
}

void AForm::beSigned(Bureaucrat &b)
{
	if (b.getGrade() <= mGradeToSign)
		mIsSigned = true;
	else
		throw GradeTooLowException();
}

std::string AForm::getName() const
{
	return mName;
}

int AForm::getGradeToExcute() const
{
	return mGradeToExcute;
}

int AForm::getGradeToSign() const
{
	return mGradeToSign;
}

bool AForm::isSigned() const
{
	return mIsSigned;
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
	os << form.getName() << ", grade to sign: " << form.getGradeToSign() << ", grade to excute: " << form.getGradeToExcute();
	return os;
}
