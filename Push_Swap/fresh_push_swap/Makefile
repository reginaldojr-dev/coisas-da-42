NAME = push_swap
BONUS = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c parser.c parser_token.c parser_value.c utils.c index.c ops.c \
	op_name.c sort_small.c sort_chunk.c sort_radix.c bench.c
BONUS_SRCS = checker_bonus.c checker_parse_bonus.c checker_read_bonus.c \
	checker_exec_bonus.c parser_token.c parser_value.c parser.c utils.c \
	index.c ops.c op_name.c
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(BONUS)

$(BONUS): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: all bonus clean fclean re
