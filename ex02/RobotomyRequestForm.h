#include "AForm.h"

class RobotomyRequestForm: public AForm
{
public:
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	~RobotomyRequestForm();

	void excute(const Bureaucrat &excutor) const;
	int count;

private:
	RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);
	RobotomyRequestForm();
	std::string mTarget;
};

