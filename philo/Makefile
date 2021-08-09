NAME			=		philo

HEADER			=		incs/philo.h

CC				=		@gcc

CFLAGS			=		-Wall -Wextra -Werror -g3 -pthread 

SRCS			=		srcs/main.c \
						srcs/parsing/parsing.c \
						srcs/philo_function.c \
						srcs/action/actions.c \
						srcs/action/fork_actions.c \
						srcs/time.c \
						srcs/action/aff_action.c \
						srcs/utils/ft_atoll.c \
						srcs/utils/ft_bzero.c \
						srcs/exit.c \
						srcs/death.c

OBJS			=		$(SRCS:.c=.o)

all				:		$(NAME)


$(NAME)		: $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -I $(HEADER) -o $(NAME)
		@echo "\033[34m[philo] Compiled\033[0m"

%.o: %.c $(HEADER)
		$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

clean		:
		@echo "\033[32m[philo] Clean\033[0m"
		@rm -f $(OBJS)

fclean		:
		@echo "\033[32m[philo] Clean\033[0m"
		@rm -f $(OBJS)
		@rm -f $(NAME)

re			:		fclean all

.PHONY: all bonus clean fclean re


