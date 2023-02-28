#include "Bureaucrat.h"
#include <ostream>

Bureaucrat::Bureaucrat(const std::string& name)
	: mName(name), mGrade(LOWEST_GRADE)
{
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
	: mName(name)
{
	if (grade < HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
	
	mGrade = grade;
}


Bureaucrat::Bureaucrat(const Bureaucrat& other)
	: mName(other.getName()), mGrade(other.getGrade())
{
}


std::string Bureaucrat::getName() const
{
	return mName;
}

int Bureaucrat::getGrade() const
{
	return mGrade;
}

void Bureaucrat::promote()
{
	if (mGrade == HIGHEST_GRADE)
		throw GradeTooHighException();
	--mGrade;
}

void Bureaucrat::demote()
{
	if(mGrade == LOWEST_GRADE)
		throw GradeTooLowException();
	++mGrade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat's grade can't higher than 1";
};

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat's grade can't lower than 150";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureucrat grade " << bureaucrat.getGrade();
	return os;
}
	