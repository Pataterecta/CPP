NAME = Zombie

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98
# -g3 -fsanitize=address,undefined

SRCS = 	main.cpp \
		Zombie.cpp \
		zombieHorde.cpp
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