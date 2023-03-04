NAME := xExcept

CC := c++
CFLAG := -Wall -Wextra -Werror -std=c++98

SRC := main.cpp \
	Bureaucrat.cpp


$(NAME): $(SRC)
	$(CC) $(CFLAG) $(SRC) -o $(NAME)

clean:
	rm -f $(NAME)

fclaen: clean

re: fclaen
	make
