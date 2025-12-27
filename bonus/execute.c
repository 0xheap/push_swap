# include "../checker_bonus.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 || *s2) 
	{
		if (*s1 != *s2)
			return (0);
		s1++;
		s2++;
	}
	return (1);
}

void	execute(t_stack **a, t_stack **b, char *op)
{
	if (ft_strcmp(op, "sa"))
		sa(a);
	else if (ft_strcmp(op, "sb"))
		 sb(b);
	else if (ft_strcmp(op, "ss"))
		ss(a, b);
	else if (ft_strcmp(op, "pa"))
		 pa(a, b);
	else if (ft_strcmp(op, "pb"))
		 pb(a, b);
	else if (ft_strcmp(op, "ra"))
		ra(a);
	else if (ft_strcmp(op, "rb"))
		rb(b);
	else if (ft_strcmp(op, "rr"))
		rr(a, b);
	else if (ft_strcmp(op, "rra"))
		rra(a);
	else if (ft_strcmp(op, "rrb"))
		rrb(b);
	else if (ft_strcmp(op, "rrr"))
		rrr(a, b);
}
