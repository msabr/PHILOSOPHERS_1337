SRC =	basic_func_bonus.c\
		display_bonus.c\
		errors_bonus.c\
		init_bonus.c\
		monitor_bonus.c\
		parssing_bonus.c\
		routine_bonus.c\
		processes_bonus.c\
		time_bonus.c\
		main_bonus.c

OBJS = $(SRC:.c=.o)

NAME = philo_bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

HEADERS = philo.h

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $^ -o $@
		make clean

%.o: %.c $(HEADERS)
		$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean
