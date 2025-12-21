/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdessel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 18:05:19 by abdessel          #+#    #+#             */
/*   Updated: 2025/11/04 18:05:19 by abdessel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hex_handler(unsigned long n)
{
	char	*hex;
	char	buffer[16];
	int		i;
	int		count;

	hex = "0123456789abcdef";
	if (n == 0)
		return (write(1, "0", 1));
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

int	ft_putpointer(void *ptr)
{
	int				count;
	unsigned long	addr;

	count = 0;
	if (ptr == NULL)
	{
		return (write(1, "(nil)", 5));
	}
	addr = (unsigned long)ptr;
	count += write(1, "0x", 2);
	count += ft_hex_handler(addr);
	return (count);
}
