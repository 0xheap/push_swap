#include "../push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void	free_data(t_data *data)
{
	if (data->numbers)
	{
		free(data->numbers);
		data->numbers = NULL;
	}
	data->count = 0;
}

void	free_all(t_stack **a, t_stack **b, t_data *data)
{
	free_stack(a);
	free_stack(b);
	free_data(data);
}
