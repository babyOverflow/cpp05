#include "Form.h"

Form::Form(std::string name, int grade)
	:mName(name), mIsSigned(false), mGradeToSign(grade), mGradeToExcute(grade)
{
	if (grade < HIGHEST_GRADE)
		throw GradeTooHighException();
	else if (grade > LOWEST_GRADE)
		throw GradeTooLowException();
}

Form::Form(std::string name, int gradeToSign, int gradeToExcute)
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

Form::Form(const Form& other)
	:mName(other.getName()),
	mIsSigned(other.mIsSigned),
	mGradeToSign(other.mGradeToSign),
	mGradeToExcute(other.mGradeToExcute)
{
}

Form::~Form()
{}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Form grade too high exception";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Form grade too low exception";
}

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

int Form::getGradeToExcute() const
{
	return mGradeToExcute;
}

int Form::getGradeToSign() const
{
	return mGradeToSign;
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << form.getName() << ", grade to sign: " << form.getGradeToSign() << ", grade to excute: " << form.getGradeToExcute();
	return os;
}
