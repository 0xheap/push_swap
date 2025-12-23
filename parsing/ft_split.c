#include "../push_swap.h"

void	free_items(char **items, int item_count)
{
	while (item_count)
		free(items[--item_count]);
	free(items);
}

static char	*split_word(char *str, char separator, int *pos)
{
	size_t	size;

	size = 0;
	while (str[*pos] == separator)
    	*pos += 1;
	while ( str[size + *pos] && str[size + *pos] != separator)
    	size++;
	return (ft_substr(str, *pos, size));
}

char	**ft_split(char *str, char separator)
{
	char	**items;
	int		pos;

	size_t (item_count), (i);
	item_count = word_count(str, separator);
	if (!item_count)
    	return (NULL);
	items = malloc(sizeof(char *) * (item_count + 1));
	if (!items)
    	return (NULL);
	pos = 0;
	i = 0;
	while (i < item_count)
	{
    	items[i] = split_word(str, separator, &pos);
     	if (!items[i])
      	{
       		free_items(items, i);
         	return (NULL);
       	}
      	pos += ft_strlen(items[i]);
       	i++;
	}
	items[i] = NULL;
	return (items);
}
