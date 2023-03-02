#ifndef FORM_H
# define FORM_H
#include <exception>
#include <string>
#include "Bureaucrat.h"

class AForm
{
public:
	AForm(std::string name, int grade);
	AForm(std::string name, int gradeToSign, int gradeToExcute);
	AForm(const AForm& other);
	virtual ~AForm();

	std::string getName() const;
	int getGradeToSign() const;
	int getGradeToExcute() const;
	bool isSigned() const;
	void beSigned(Bureaucrat& b);
	virtual void excute(Bureaucrat const & excutor) const = 0;

	static const int HIGHEST_GRADE = Bureaucrat::HIGHEST_GRADE;
	static const int LOWEST_GRADE = Bureaucrat::LOWEST_GRADE;

class GradeTooHighException: public std::exception
{
public:
	const char* what() const throw();
};

class GradeTooLowException: public std::exception
{
public:
	const char* what() const throw();
};

class ExecuteUnsignedForm: public std::exception
{
public:
	const char* what() const throw();
};

private:
	AForm();
	AForm& operator=(const AForm& rhs);

	const std::string mName;
	bool mIsSigned;
	const int mGradeToSign;
	const int mGradeToExcute;
};

std::ostream& operator<<(std::ostream& os, const AForm& bureaucrat);
#endif //FORM_H
