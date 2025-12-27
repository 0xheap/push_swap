NAME        = 	push_swap
BNAME		=	checker

PARSING_DIR = 	parsing

PARSING_SRC = 	any_double.c \
				count_total_nums.c  ft_atoi.c \
		  		ft_split.c  ft_strlen.c  ft_substr.c \
				range_validate.c  validate_chars.c  word_count.c

STACK_DIR = stack
STACK_SRC =	ft_lst_utils.c


BONUS_PARSING_DIR = bonus/parsing_bonus
BONUS_PARSING_SRC = any_double.c ft_atoi.c ft_strlen.c is_legal.c\
					validate_chars.c count_total_nums.c  ft_split.c  ft_substr.c\
					range_validate.c  word_count.c
BONUS_OPS_DIR 	  = bonus/operations
BONUS_OPS_SRC 	  = push.c  reverse.c  rotate.c  swap.c
BONUS_STACK_DIR = bonus/stack
BONUS_STACK_SRC =	ft_lst_utils.c





SRCS        = 	main.c\
			  	validate_args.c\
				$(addprefix $(PARSING_DIR)/, $(PARSING_SRC))\
				$(addprefix $(STACK_DIR)/, $(STACK_SRC))\
				operations/swap.c operations/push.c operations/rotate.c operations/reverse.c\
			 	sort/sort_stack.c sort/sort_stack_1.c sort/sort_5.c sort/turk.c sort/turk_utils.c\
				free/free_all.c message.c
				
BSRCS		= checker_bonus.c bonus/validate_args.c bonus/read_line.c bonus/execute.c\
			  $(addprefix $(BONUS_PARSING_DIR)/, $(BONUS_PARSING_SRC))\
			  $(addprefix $(BONUS_OPS_DIR)/, $(BONUS_OPS_SRC))\
			  $(addprefix $(BONUS_STACK_DIR)/, $(BONUS_STACK_SRC))\
			  free/free_all.c bonus/message.c


OBJS        = $(SRCS:.c=.o)
BOBJS		= $(BSRCS:.c=.o)

# Compiler flags (mandatory at 42)
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g

INCLUDES    = -I.

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

bonus: $(BNAME)

$(BNAME): $(BOBJS)
	$(CC) $(CFLAGS) $(BOBJS) -o $(BNAME)

clean:
	rm -f $(OBJS) $(BOBJS)

fclean: clean
	rm -f $(NAME) $(BNAME)

re: fclean all

.PHONY: all clean fclean re bonus
.SECONDARY: $(OBJS)
