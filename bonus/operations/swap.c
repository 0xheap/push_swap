#include "../../checker_bonus.h"

static void	swap(t_stack **stack)
{
	t_stack	*node1;
	t_stack	*node2;
	t_stack	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	node1 = *stack;
	node2 = node1->next;
	tmp = node2->next;
	*stack = node2;
	node2->next = node1;
	node1->next = tmp;
}

void	sa(t_stack **stack)
{
	swap(stack);
}

void	sb(t_stack **stack)
{
	swap(stack);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
}