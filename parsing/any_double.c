# include "../push_swap.h"

void	ft_any_double(t_argval *s_parse, t_data *s_numbers)
{

	int i, (j);
	i = 0;
	while (i < s_numbers->count)
	{
		j = i + 1;
		while (j < s_numbers->count)
		{
			if (s_numbers->numbers[i] == s_numbers->numbers[j])
				s_parse->error = 1;
			j++;
		}
		i++;
	}
}
