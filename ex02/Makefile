COMP = c++

NAME = Bureaucrat

SRC = main.cpp \
	Bureaucrat.cpp \
	AForm.cpp \
	ShrubberyCreationForm.cpp \
	RobotomyRequestForm.cpp \
	PresidentialPardonForm.cpp

FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRC)
	$(COMP) $(FLAGS) $(SRC) -o $(NAME)
	@echo "\033[92mBureaucrat is ready!\033[0m"

clean:

fclean: clean
	rm -f $(NAME)
	@echo "\033[92mBureaucrat is deleted!\033[0m"

re: fclean all

.PHONY: all clean fclean re

.SILENT:
