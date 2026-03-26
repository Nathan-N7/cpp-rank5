NAME = ScalarConverter
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = ScalarConverter.cpp main.cpp
LIB = ScalarConverter.hpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)

.cpp.o $(LIB):
	$(CC) $(FLAGS) -c $< -o $@
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re