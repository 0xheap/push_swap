# include "../../checker_bonus.h"

static int	get_operation(char *str, char *operation)
{
	int	i;
	int	j;
	
	i = 0;
	while (str[i]) {
		j = 0;
		while (operation[j] == str[i + j])
			j++;
		if (operation[j] == '\0')
			return (1);
		i++;
	}
	return (0);
}

void	is_legal(t_argval *s_parce, char *operation)
{
	char *str = "sa sb ss pa pb ra rb rr rra rrb rrr";
	if(get_operation(str, operation))
		return ;
	else
		s_parce->error = 1;
}