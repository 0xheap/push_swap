# include "../push_swap.h"

int	find_smallest(t_stack **stack)
{
	t_stack	*current;

	int	pos, (i), (record);
	current = *stack;
	i = 0;
	pos = 0;
	record = current->value;
	while (current) 
	{
		if (current->value < record)
		{
			record = current->value;
			pos = i;
		}
		current = current->next;
		i++;
	}
	return (pos);
}

static int	already(t_stack **stack)
{
		int  a;
		int	 b;
		int	 c;
		int	 d;
		int  e;
		
		a = (*stack)->value;
		b = (*stack)->next->value;
		c = (*stack)->next->next->value;
		d = (*stack)->next->next->next->value;
		e = (*stack)->next->next->next->next->value;
		if (a < b && b < c && c < d && d < e)
			return (1);
		return (0);
}

static void sort_it_5(t_stack **stack_a,t_stack **stack_b, int pos)
{
	if (pos == 0)
		pb(stack_a, stack_b);
	else if (pos == 1)
	{
		sa(stack_a);
		pb(stack_a, stack_b);
	}
	else if (pos == 2)
	{
		ra(stack_a);
		sa(stack_a);
		pb(stack_a, stack_b);
	}
	else if (pos == 3)
	{
		rra(stack_a);
		rra(stack_a);
		pb(stack_a, stack_b);
	}
	else if (pos == 4)
	{
		rra(stack_a);
		pb(stack_a, stack_b);
	}
}

void	sort_5(t_stack **stack_a,t_stack **stack_b)
{
	int pos;
	if (already(stack_a))
		return ;
	pos = find_smallest(stack_a);
	sort_it_5(stack_a, stack_b, pos);
	sort_4(stack_a, stack_b);
	pa(stack_a, stack_b);
}