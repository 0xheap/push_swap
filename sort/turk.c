#include "../push_swap.h"

// Had FUnction Kadir return l how many on which operation i should use
// if it return a vlaue that is bigger then size / 2 use rra
// else use ra becuse its on the half top of it
int	get_cost(int index, int size)
{
	if (index <= (size / 2))
		return (index);
	return (size - index);
}

void	get_dir_cost(int idx, int size, int *dir, int *cost)
{
	if (idx <= size / 2)
	{
		*dir = 1;
		*cost = idx;
	}
	else
	{
		*dir = 0;
		*cost = size - idx;
	}
}

void	do_rotations(t_stack **a, t_stack **b, int idx_a, int idx_b)
{
	int	dir_a;
	int	dir_b;
	int	cost_a;
	int	cost_b;

	get_dir_cost(idx_a, stack_size(a), &dir_a, &cost_a);
	get_dir_cost(idx_b, stack_size(b), &dir_b, &cost_b);
	while (cost_a > 0 && cost_b > 0 && dir_a && dir_b)
	{
		rr(a, b);
		cost_a--;
		cost_b--;
	}
	while (cost_a > 0 && cost_b > 0 && !dir_a && !dir_b)
	{
		rrr(a, b);
		cost_a--;
		cost_b--;
	}
	while (cost_a-- > 0)
	{
		if (dir_a)
			ra(a);
		else
			rra(a);
	}
	while (cost_b-- > 0)
	{
		if (dir_b)
			rb(b);
		else
			rrb(b);
	}
}

static int	calc_total_cost(int idx_a, int idx_b, int size_a, int size_b)
{
	int	dir_a;
	int	dir_b;
	int	cost_a;
	int	cost_b;

	get_dir_cost(idx_a, size_a, &dir_a, &cost_a);
	get_dir_cost(idx_b, size_b, &dir_b, &cost_b);
	if (dir_a == dir_b)
	{
		if (cost_a > cost_b)
			return (cost_a);
		return (cost_b);
	}
	return (cost_a + cost_b);
}

int	find_cheapest(t_stack *a, t_stack *b)
{
	int		cheapest;
	int		cost;
	int		min_cost;
	int		idx_a;
	int		idx_b;
	t_stack	*tmp;

	tmp = a;
	min_cost = 2147483647;
	cheapest = tmp->value;
	while (tmp)
	{
		idx_a = get_index(a, tmp->value);
		idx_b = find_target_position(b, tmp->value);
		cost = calc_total_cost(idx_a, idx_b, stack_size(&a), stack_size(&b));
		if (cost < min_cost)
		{
			min_cost = cost;
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
	int	i;

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
	sort_3(a);
	while (stack_size(b) > 0)
	{
		i = 0;
		idx_a = find_target_in_a(*a, (*b)->value);
		if (idx_a <= stack_size(a) / 2)
			while (i++ < idx_a)
				ra(a);
		else
			while (i++ < (stack_size(a) - idx_a))
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
