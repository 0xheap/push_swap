#include "ft_printf/ft_printf.h"
#include "push_swap.h"

// int validate_args(int ac, char **av)
// {
//     t_argval s_parse;
//     int i;

//     i = 1;
//     while (i < ac)
//     {
//         ft_atoi(&s_parse, av[i]);
//         if (s_parse.error == 1)
//             ft_printf("error in arg %d: %s\n", i, av[i]);
//         i++;
//     }

//     return (1);
// }

int main (int ac, char **av)
{
	t_data		s_numbers;
	
	s_numbers = (t_data){0};
    if (ac == 1)
        return (0);
    if (!validate_args(ac, av, &s_numbers))
   		ft_printf("%s\n", "Error Here");
    else
    	ft_printf("%s\n", "ALL ABRGS ARE VALID");
}
