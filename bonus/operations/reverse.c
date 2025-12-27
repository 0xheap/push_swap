#include "../../checker_bonus.h"

static void	reverse(t_stack **stack)
{
	t_stack	*tail;
	t_stack	*head;
	t_stack	*prev;

	if (!*stack || !(*stack)->next)
		return ;
	head = *stack;
	tail = *stack;
	while (tail->next != NULL)
	{
		prev = tail;
		tail = tail->next;
	}
	*stack = tail;
	tail->next = head;
	prev->next = NULL;
}

void	rra(t_stack **stack)
{
	reverse(stack);
}

void	rrb(t_stack **stack)
{
	reverse(stack);
}

void	rrr(t_stack **stackx, t_stack **stacky)
{
	reverse(stackx);
	reverse(stacky);
}