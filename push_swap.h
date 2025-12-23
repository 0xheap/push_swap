#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>


typedef struct	s_argval
{
    long	value;           // Parsed long value (for int overflow check)
    int		error;           // 1 if error found, 0 otherwise
    int		multiple_signs;  // 1 if more than one sign found, 0 otherwise
    int		has_digits;      // 1 if at least one digit found, 0 otherwise
    int		count;			 // Helper In Duplicate number
}	t_argval;

typedef struct	s_data
{
    int		*numbers;        // Array of all validated numbers
    int		count;           // Total count of numbers
}	t_data;


typedef struct	stack
{
	int	value;
	struct stack	*next;
}	t_stack;


// Parsing functions
void	ft_atoi(t_argval *s_parse, char *str);
void	validate_chars(t_argval *s_parse, int ac, char **av);
int		ft_int_range(long result);
void	ft_any_double(t_argval *s_parse, t_data *s_numbers);
// String utilities
char	**ft_split(char *str, char separator);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(char *str);
size_t	word_count(char *str, char separator);
size_t	count_total_nums(int ac, char **av);
void	free_items(char **items, int item_count);
// Main validation
int	validate_args(int ac, char **av, t_data *s_numbers);

// Stack Utils
t_stack	*lstnew(int value);
void	lst_add_front(t_stack **lst, t_stack *new_node);
void	lst_add_back(t_stack **lst, t_stack *new_node);
// Operations
void	sa(t_stack **stack);
void	sb(t_stack **stack);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack);
void	rrb(t_stack **stack);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	rrr(t_stack **stackx, t_stack **stacky);
void	rb(t_stack **stack);
void	ra(t_stack **stack);
// sort algo
void	sort(t_stack **stack_a, t_stack **stack_b, t_data *s_numbers); 
void	sort_3(t_stack **stack);
void	sort_2(t_stack **stack);
void	sort_4(t_stack **stack_a, t_stack **stack_b);

#endif
