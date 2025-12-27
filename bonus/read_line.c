# include "../checker_bonus.h"
#include <stdlib.h>

char	*read_operations(int fd)
{
	char	*operation;
	char	c;
	int		i;

	operation = malloc(8);
	i = 0;
	while ((read(fd, &c, 1)) > 0 && c != '\n') {
		operation[i++] = c;
	}
	operation[i] = '\0';
	if (i == 0)
	{
		free(operation);
		return (NULL);
	}
	return (operation);
}