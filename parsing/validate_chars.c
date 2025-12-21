# include "../push_swap.h"

static int  only_snum(char *str)
{
    while(*str)
    {
        if (!(*str ==  ' ' || (*str >= '0' && *str <= '9') || *str ==  '-'
        				   || *str ==  '+'))
            return (0);
        str++;
    }
    return (1);
}

void validate_chars(t_argval *s_parce, int ac, char **av)
{
    int i;

    i = 1;
    while (i < ac)
    {
        if (!only_snum(av[i]))
        {
            s_parce->error = 1;
            return ;
        }
        i++;
    }
}
