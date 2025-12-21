NAME        = 	push_swap

PRINTF_DIR  = 	ft_printf
PRINTF      = 	$(PRINTF_DIR)/libftprintf.a

PARSING_DIR = 	parsing

PARSING_SRC = 	any_double.c \
				count_total_nums.c  ft_atoi.c \
		  		ft_split.c  ft_strlen.c  ft_substr.c \
				range_validate.c  validate_chars.c  word_count.c

SRCS        = 	main.c\
			  	validate_args.c\
				$(addprefix $(PARSING_DIR)/, $(PARSING_SRC))

OBJS        = $(SRCS:.c=.o)

# Compiler flags (mandatory at 42)
CC          = cc
CFLAGS      = -Wall -Wextra -Werror

INCLUDES    = -I. -I$(PRINTF_DIR)

all: $(NAME)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

$(NAME): $(PRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
.SECONDARY: $(OBJS)
