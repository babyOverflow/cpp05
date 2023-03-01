#include "AForm.h"

class ShrubberyCreationForm: public AForm
{
public:
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	~ShrubberyCreationForm();

	void excute(const Bureaucrat &excutor) const;

private:
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs);
	ShrubberyCreationForm();
	std::string mTarget;
};
