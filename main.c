#include "ft_printf/ft_printf.h"
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	t_data	s_numbers;
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*node;
	int		i;

	s_numbers = (t_data){0};
	if (ac == 1 || (ac == 2 && word_count(av[1], ' ') == 1))
		return (1);
	if (!validate_args(ac, av, &s_numbers))
	{
		ft_printf("%s\n", "Error");
		return (1);
	}
	i = 0;
	stack_a = NULL;
	stack_b = NULL;
	node = NULL;
	while (i < s_numbers.count)
	{
		node = lstnew(s_numbers.numbers[i]);
		if (!node)
			return (1);
		lst_add_back(&stack_a, node);
		i++;
	}
	sort(&stack_a, &stack_b, &s_numbers);
	free_all(&stack_a, &stack_b, &s_numbers);
	return (0);
}
