NAME := xExcept

CC := c++
CFLAG := -Wall -Wextra -Werror -std=c++98

SRC := main.cpp \
	Bureaucrat.cpp \
	AForm.cpp \
	ShrubberyCreationForm.cpp \
	RobotomyRequestForm.cpp \
	PresidentialPardonForm.cpp \
	Intern.cpp


$(NAME): $(SRC)
	$(CC) $(CFLAG) $(SRC) -o $(NAME)

clean:
	rm -f $(NAME)

fclaen: clean

re: fclaen
	make
