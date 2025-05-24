CC = cc -pthread 
Cflags = -Wall -Wextra -Werror 
NAME = philo
RM = rm -f

SRCS = main.c parsing.c having_seats.c dinner.c doing_dishes.c \
		eat_sleep_think.c checks.c utils.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) 
		$(CC) $(Cflags) $(OBJS) -o $(NAME)

%.o: %.c philo.h
		$(CC) $(Cflags) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re