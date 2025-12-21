/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdessel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:48:59 by abdessel          #+#    #+#             */
/*   Updated: 2025/11/04 11:48:59 by abdessel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, char format)
{
	char	*hex;
	char	buffer[16];
	int		count;
	int		i;

	if (format == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (n == 0)
		return (ft_putchar('0'));
	count = 0;
	i = 0;
	while (n > 0)
	{
		buffer[i++] = hex[n % 16];
		n /= 16;
	}
	while (i > 0)
	{
		count += ft_putchar(buffer[--i]);
	}
	return (count);
}
/*
int	main(void)
{
	printf("\n%d", ft_puthex(20, 'X'));
}
*/
