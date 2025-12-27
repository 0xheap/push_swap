#include "../push_swap.h"
#include <stddef.h>

/*
** stack_size: Count chal element f stack
** Return: number of nodes f stack
*/
int	stack_size(t_stack **stack)
{
	int		size;
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

/*
** find_min: L9a SMALLEST value f stack
** Return: smallest number
*/
int	find_min(t_stack *stack)
{
	int	min;

	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

/*
** find_max: L9a BIGGEST value f stack
** Return: biggest number
*/
int	find_max(t_stack *stack)
{
	int	max;

	max = stack->value;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

/*
** get_index: L9a INDEX (position) dyal value f stack
** Return: position (0 = TOP)
*/
int	get_index(t_stack *stack, int value)
{
	int	pos;

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

/*
** find_target_position: L9a TARGET f B bach element ymchi fo9o
** Rule: TARGET = BIGGEST element f B li SGHAR men value
** Special case: ila value > MAX wla < MIN → target = MAX
** Return: INDEX dyal target f stack_b
*/
int	find_target_position(t_stack *stack_b, int value)
{
	int		closest;
	t_stack	*tmp;

	// Ila value KBAR men MAX wla SGHAR men MIN → target = MAX
	if (value > find_max(stack_b) || value < find_min(stack_b))
		return (get_index(stack_b, find_max(stack_b)));
	// L9a BIGGEST element li SGHAR men value
	closest = find_min(stack_b);
	tmp = stack_b;
	while (tmp)
	{
		if (tmp->value < value && tmp->value > closest)
			closest = tmp->value;
		tmp = tmp->next;
	}
	return (get_index(stack_b, closest));
}

/*
** find_target_in_a: L9a TARGET f A bach element men B ymchi t7to
** Rule: TARGET = SMALLEST element f A li KBAR men value
** Special case: ila value > MAX → target = MIN
** Return: INDEX dyal target f stack_a
*/
int	find_target_in_a(t_stack *stack_a, int value)
{
	int		closest;
	t_stack	*tmp;

	if (value > find_max(stack_a))
		return (get_index(stack_a, find_min(stack_a)));
	closest = find_max(stack_a);
	tmp = stack_a;
	while (tmp)
	{
		if (tmp->value > value && tmp->value < closest)
			closest = tmp->value;
		tmp = tmp->next;
	}
	return (get_index(stack_a, closest));
}
