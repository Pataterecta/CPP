NAME = Bureau

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 
#-g3 -fsanitize=address,undefined
#-pedantic 

SRCS = 	main.cpp \
		Bureaucrat.cpp \
		AForm.cpp \
		PresidentialPardonForm.cpp \
		RobotomyRequestForm.cpp \
		ShrubberyCreationForm.cpp

OBJS := $(SRCS:.cpp=.o)

.cpp.o:
	$(CC) $(CFLAGS) -c $<

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re