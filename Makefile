CC = cc
Cflags = -Wall -Wextra -Werror -g
NAME = philosophers
RM = rm -f

SRCS = main.c  parsing.c utils.c  dinner.c doing_dishes.c having_seats.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) 
		$(CC) $(Cflags) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all