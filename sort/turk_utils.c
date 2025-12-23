#include "../push_swap.h"
#include <stddef.h>

int	stack_size(t_stack	**stack)
{
	int	size;
	t_stack	*tmp;
	
	tmp = *stack;
	size = 0;
	while (tmp)
	{
		tmp = tmp->next;
		size++;
	}
	return (size);
}

int find_min(t_stack *stack)
{
	int	min;
	
	min = stack->value;
	while (stack) {
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

int find_max(t_stack *stack)
{
	int	max;
	
	max = stack->value;
	while (stack) {
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

int	get_index(t_stack *stack, int value)
{
	int pos;

	pos = 0;
	while (stack)
	{
		if (value == stack->value)
			break ;
		stack = stack->next;
		pos++;
	}
	return (pos);
}

int	find_target_position(t_stack *stack_b, int value)
{
	int		pos;
	t_stack	*tmp;

	if (value > find_max(stack_b) || value < find_min(stack_b))
		return (get_index(stack_b, find_max(stack_b)));
	pos = 0;
	tmp = stack_b;
	while (tmp)
	{
		if (tmp->value < value)
			return (pos);
		tmp = tmp->next;
		pos++;
	}
	return (pos);
}