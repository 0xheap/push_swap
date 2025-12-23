# include "../push_swap.h"

int	find_largest(t_stack **stack)
{
	t_stack	*current;

	int	pos, (i), (record);
	current = *stack;
	i = 0;
	pos = 0;
	record = current->value;
	while (current) 
	{
		if (current->value > record)
		{
			record = current->value;
			pos = i;
		}
		current = current->next;
		i++;
	}
	return (pos);
}

int	already(t_stack **stack)
{
	int  f;
	int	 s;
	int	 t;
	int	 l;
	
	f = (*stack)->value;
	s = (*stack)->next->value;
	t = (*stack)->next->next->value;
	l = (*stack)->next->next->next->value;
	if (f < s && s < t && t < l)
		return (1);
	return (0);
}

void	sort_4(t_stack **stack_a, t_stack **stack_b)
{
	int pos;

	if (already(stack_a))
		return ;
	pos = find_largest(stack_a);
	if (pos == 0)
	{
		pb(stack_a, stack_b);
		sort_3(stack_a);
		pa(stack_a, stack_b);
		ra(stack_a);
	}
	else if (pos == 1) 
	{
		ra(stack_a);
		pb(stack_a, stack_b);
		sort_3(stack_a);
		pa(stack_a, stack_b);
		ra(stack_a);
	}
	else if (pos == 2) 
	{
		ra(stack_a);
		ra(stack_a);
		pb(stack_a, stack_b);
		sort_3(stack_a);
		pa(stack_a, stack_b);
		ra(stack_a);
	}
	else if (pos == 3) 
	{
		rra(stack_a);
		pb(stack_a, stack_b);
		sort_3(stack_a);
		pa(stack_a, stack_b);
		ra(stack_a);
	}
}
