#include "checker_bonus.h"
#include <unistd.h>

int is_sorted(t_stack *stack)
{
    while (stack && stack->next)
    {
        if (stack->value > stack->next->value)
            return (0);
        stack = stack->next;
    }
    return (1);
}


int	main(int ac, char **av)
{
	t_data	s_numbers;
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*node;
	t_argval	s_parse;
	char	*operation;
	int		i;

	s_numbers = (t_data){0};
	s_parse = (t_argval){0};
	
	if (!av[1])
		return (0);
	if (!validate_args(ac, av, &s_numbers))
	{
		message(2, "Error\n");
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
	
	while ((operation = read_operations(0)))
	{
		is_legal(&s_parse, operation);
		if (s_parse.error == 1)
		{
			free_all(&stack_a, &stack_b, &s_numbers);
			message(2, "Error\n");
			return (1);
		}
		execute(&stack_a, &stack_b, operation);
	}
	if (!is_sorted(stack_a) || stack_b)
	{
		message(1, "KO\n");
		free_all(&stack_a, &stack_b, &s_numbers);
		return (1);
	}
	message(1, "OK\n");
	free_all(&stack_a, &stack_b, &s_numbers);
	return (0);
}
