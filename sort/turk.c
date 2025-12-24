#include "../push_swap.h"

// Had FUnction Kadir return l how many on which operation i should use 
// if it return a vlaue that is bigger then size / 2 use rra
// else use ra becuse its on the half top of it
int	get_cost(int index, int size)
{
	if (index <= size / 2)
    	return (index);
	return (size - index);
}

void do_rotations(t_stack **a, t_stack **b, int idx_a, int idx_b)
{
		int i = 0;
		int j = 0;
		int size_a = stack_size(a);
		int size_b = stack_size(b);

		if (idx_a <= size_a / 2)
			while (i++ < idx_a)
				ra(a);
		else
			while (i++ < size_a - idx_a)
				rra(a);

		if (idx_b <= size_b / 2)
			while (j++ < idx_b)
				rb(b);
		else
			while (j++ < size_b - idx_b)
				rrb(b);
}

int	find_cheapest(t_stack *a, t_stack *b)
{
	t_stack *tmp;
	int	cost_a;
	int	cost_b;
	int cheapest;
	int small;
	
	tmp = a;
	cost_a = get_cost(get_index(a, tmp->value), stack_size(&a));
	cost_b = get_cost(find_target_position(b, tmp->value), stack_size(&b));
	small = cost_a + cost_b;
	cheapest = tmp->value;
	while (tmp)
	{
		cost_a = get_cost(get_index(a, tmp->value), stack_size(&a));
		cost_b = get_cost(find_target_position(b, tmp->value), stack_size(&b));
		if (cost_a + cost_b < small)
		{
			small = cost_a + cost_b;
			cheapest = tmp->value;
		}
		tmp = tmp->next;
	}
	return (cheapest);
}

void	turk(t_stack **a, t_stack **b)
{
	int	cheapest;
	int	idx_a;
	int	idx_b;

	pb(a, b);
	pb(a, b);

	while (stack_size(a) > 3)
	{
		cheapest = find_cheapest(*a, *b);
		idx_a = get_index(*a, cheapest);
		idx_b = find_target_position(*b, cheapest);
		do_rotations(a, b, idx_a, idx_b);
		pb(a, b);
	}
	// TODO: sort_3, push back to A, final rotation
	sort_3(a);
	while (stack_size(b) > 0)
	{
	    idx_a = find_target_in_a(*a, (*b)->value);
	    // rotate A bach target ywsel TOP
	    if (idx_a <= stack_size(a) / 2)
	        while (idx_a-- > 0)
	            ra(a);
	    else
	        while (idx_a++ < stack_size(a))
	            rra(a);
	    pa(a, b);
	}
	idx_a = get_index(*a, find_min(*a));
	if (idx_a <= stack_size(a) / 2)
    	while (idx_a-- > 0)
        	ra(a);
    else
    	while (idx_a++ < stack_size(a))
        	rra(a);
}
