#include "../../checker_bonus.h"

size_t	count_total_nums(int ac, char **av)
{
	size_t	total;
	int		i;

	total = 0;
	i = 1;
	while (i < ac)
	{
		total += word_count(av[i], ' ');
		i++;
	}
	return (total);
}
