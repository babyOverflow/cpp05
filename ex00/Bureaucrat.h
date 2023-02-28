#include <exception>
#include <ostream>
#include <string>

class Bureaucrat
{
public:
	Bureaucrat(const std::string& name);
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& other);
	~Bureaucrat();
	// Bureaucrat& operator=(const Bureaucrat& rhs) = delete;

	std::string getName() const;
	int getGrade() const;
	void promote();
	void demote();

	static const int HIGHEST_GRADE = 1;
	static const int LOWEST_GRADE = 150;

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
	Bureaucrat();
	Bureaucrat& operator=(const Bureaucrat& rhs);
	const std::string mName;
	int mGrade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);