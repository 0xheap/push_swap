# include "../push_swap.h"

static int skip_whitespace(char *str, int i)
{
    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    return (i);
}

static int parse_sign(char *str, int i, t_argval *s_parse, int *sign)
{
    while (str[i] == '+' || str[i] == '-')
    {
        if (s_parse->multiple_signs == 1)
        {
            s_parse->error = 1;
            break;
        }
        if (str[i] == '-')
            *sign = -1;
        s_parse->multiple_signs = 1;
        i++;
    }
    return (i);
}

static int parse_digits(char *str, int i, t_argval *s_parse, int sign)
{
    while (str[i] >= '0' && str[i] <= '9')
    {
        s_parse->value = s_parse->value * 10 + (str[i] - '0');
        if (!ft_int_range((s_parse->value) * sign))
        {
            s_parse->error = 1;
            break;
        }
        s_parse->has_digits = 1;
        i++;
    }
    return (i);
}

void ft_atoi(t_argval *s_parse, char *str)
{
    int sign;
    int i;

    *s_parse = (t_argval){0};
    sign = 1;
    i = 0;
    if (!*str)
    {
        s_parse->error = 1;
        return ;
    }
    i = skip_whitespace(str, i);
    i = parse_sign(str, i, s_parse, &sign);
    i = parse_digits(str, i, s_parse, sign);
    i = skip_whitespace(str, i);
    if (str[i] != '\0' || s_parse->has_digits == 0)
        s_parse->error = 1;
    s_parse->value *= sign;
}
