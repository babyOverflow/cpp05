#include "AForm.h"

class PresidentialPardonForm: public AForm
{
public:
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm& other);
	~PresidentialPardonForm();

	void excute(const Bureaucrat &excutor) const;
	int count;

private:
	PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);
	PresidentialPardonForm();
	std::string mTarget;
};


