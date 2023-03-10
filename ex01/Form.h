#ifndef FORM_H
# define FORM_H
#include <string>
#include "Bureaucrat.h"

class Form
{
public:
	Form(std::string name, int grade);
	Form(std::string name, int gradeToSign, int gradeToExcute);
	Form(const Form& other);
	~Form();

	std::string getName() const;
	int getGradeToSign() const;
	int getGradeToExcute() const;
	void beSigned(Bureaucrat& b);

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

private:
	Form();
	Form& operator=(const Form& rhs);

	const std::string mName;
	bool mIsSigned;
	const int mGradeToSign;
	const int mGradeToExcute;
};

std::ostream& operator<<(std::ostream& os, const Form& bureaucrat);
#endif //FORM_H
