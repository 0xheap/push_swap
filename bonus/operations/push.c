#include "../../checker_bonus.h"

static void	push(t_stack **src, t_stack **dst)
{
	t_stack	*top;

	if (!*src)
		return ;
	top = *src;
	*src = top->next;
	lst_add_front(dst, top);
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
}
