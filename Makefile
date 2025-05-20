CC = cc -pthread
Cflags = -Wall -Wextra -Werror -g
NAME = philosophers
RM = rm -f

SRCS = main.c parsing.c having_seats.c dinner.c doing_dishes.c \
		eat_sleep_think.c checks.c utils.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) 
		@$(CC) $(Cflags) $(OBJS) -o $(NAME)
		@echo "--- Compiling the executable ---"

%.o: %.c philo.h
		@$(CC) $(Cflags) -c $< -o $@


$(OBJS): | print

print:
	@echo "--- Compiling *.c ---"

clean:
	@$(RM) $(OBJS)
	@echo "--- Cleaning up object files ---"

fclean: clean
	@$(RM) $(NAME)
	@echo "--- Cleaning up $(NAME)--- "

re: fclean all
	@echo "--- Rebuilding $(NAME) ---"

.PHONY: all clean fclean re