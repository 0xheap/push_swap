#include "../push_swap.h"


int is_sorted(t_stack *stack)
{
    while (stack && stack->next)
    {
        if (stack->value > stack->next->value)
            return (0);
        stack = stack->next;
    }
    return (1);
}

void	sort_3(t_stack **stack)
{
	int a, (b), (c);
	a = (*stack)->value;
	b = (*stack)->next->value;
	c = (*stack)->next->next->value;
	if (a < b && b < c)
		return ;
	if (a > b && b < c && a < c)
		sa(stack);
	else if (a > b && b > c)
	{
		sa(stack);
		rra(stack);
	}
	else if (a > b && b < c && a > c)
		ra(stack);
	else if (a < b && b > c && a < c)
	{
		sa(stack);
		ra(stack);
	}
	else if (a < b && b > c && a > c)
		rra(stack);
	return ;
}

void	sort_2(t_stack **stack)
{
	int	first;
	int	second;

	first = (*stack)->value;
	second = (*stack)->next->value;
	if (first < second)
		return ;
	else if (first > second)
		sa(stack);
}

void	sort(t_stack **stack_a, t_stack **stack_b, t_data *s_numbers)
{
	if (is_sorted(*stack_a))
        return ;
	if (s_numbers->count == 2)
		sort_2(stack_a);
	else if (s_numbers->count == 3)
		sort_3(stack_a);
	else if (s_numbers->count == 4)
		sort_4(stack_a, stack_b);
	else if (s_numbers->count == 5)
		sort_5(stack_a, stack_b);
	else if (s_numbers->count > 5)
		turk(stack_a, stack_b);
}
