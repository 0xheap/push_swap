#include "../checker_bonus.h"

static void	fill_in(t_argval *s_parse, t_data *s_numbers, int *n)
{
	if (!s_numbers->numbers || !n)
		return ;
	s_numbers->numbers[*n] = s_parse->value;
	*n += 1;
}

static int	ft_split_atoi(t_argval *s_parse, char *str, t_data *s_numbers,
		int *n)
{
	char	**args;
	int		size;
	int		i;

	size = word_count(str, ' ');
	args = ft_split(str, ' ');
	if (!args)
		return (0);
	i = 0;
	while (i < size)
	{
		ft_atoi(s_parse, args[i]);
		if (s_parse->error == 1)
		{
			free_items(args, size);
			return (0);
		}
		fill_in(s_parse, s_numbers, n);
		i++;
	}
	free_items(args, size);
	return (1);
}

int	validate_args(int ac, char **av, t_data *s_numbers)
{
	t_argval	s_parse;

	int i, (n);
	s_parse = (t_argval){0};
	i = 1;
	n = 0;
	validate_chars(&s_parse, ac, av);
	if (s_parse.error == 1)
		return (0);
	s_numbers->count = count_total_nums(ac, av);
	if (s_numbers->count == 0)
		return (0);
	s_numbers->numbers = malloc(sizeof(int) * s_numbers->count);
	if (!s_numbers->numbers)
		return (0);
	while (i < ac)
	{
		if (word_count(av[i], ' ') > 1)
		{
			if (!ft_split_atoi(&s_parse, av[i], s_numbers, &n))
			{
				free(s_numbers->numbers);
				return (0);
			}
		}
		else
		{
			ft_atoi(&s_parse, av[i]);
			if (s_parse.error == 1)
			{
				free(s_numbers->numbers);
				return (0);
			}
			fill_in(&s_parse, s_numbers, &n);
		}
		i++;
	}
	ft_any_double(&s_parse, s_numbers);
	if (s_parse.error == 1)
	{
		free(s_numbers->numbers);
		return (0);
	}
	return (1);
}
