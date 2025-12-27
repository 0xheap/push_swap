#include "../../checker_bonus.h"

size_t	word_count(char *str, char separator)
{
	size_t	size;
	int		in;
	size_t	i;

	if (!str)
		return (0);
	size = 0;
	in = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != separator && !in)
		{
			size += 1;
			in = 1;
		}
		else if (str[i] == separator && in)
			in = 0;
		i++;
	}
	return (size);
}
