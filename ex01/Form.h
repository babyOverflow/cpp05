#ifndef FORM_H
# define FORM_H
#include <string>
#include "Bureaucrat.h"

class Form
{
public:
	Form(std::string name, int grade);
	Form(const Form& other);
	~Form();

	std::string getName() const;
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
	const int mGradeToSign;
	const int mGradeToExcute;
	bool mIsSigned;
};
#endif //FORM_H
