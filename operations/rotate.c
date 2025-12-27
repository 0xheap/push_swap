#include "../push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*second;
	t_stack	*tail;
	t_stack	*current;

	if (!*stack || !(*stack)->next)
		return ;
	head = *stack;
	current = *stack;
	second = head->next;
	*stack = second;
	while ((current = current->next))
	{
		tail = current;
	}
	tail->next = head;
	head->next = NULL;
}

void	ra(t_stack **stack)
{
	rotate(stack);
	message(1, "ra\n");
}

void	rb(t_stack **stack)
{
	rotate(stack);
	message(1, "rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	message(1, "rr\n");
}