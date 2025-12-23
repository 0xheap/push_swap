# include "../push_swap.h"

static void	reverse(t_stack **stack)
{
    t_stack *tail;
    t_stack *head;
    t_stack *prev;

    if (!*stack || !(*stack)->next)
        return;
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
	ft_printf("%s\n", "rra");
}

void	rrb(t_stack **stack)
{
	reverse(stack);
	ft_printf("%s\n", "rrb");
}


void	rrr(t_stack **stackx, t_stack **stacky)
{
	reverse(stackx);
	reverse(stacky);
	ft_printf("%s\n", "rrr");
}