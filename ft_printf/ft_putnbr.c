/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdessel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 10:54:06 by abdessel          #+#    #+#             */
/*   Updated: 2025/11/04 10:54:06 by abdessel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int		count;
	long	num;

	count = 0;
	num = n;
	if (num < 0)
	{
		count += ft_putchar('-');
		num = -num;
	}
	if (num > 9)
		count += ft_putnbr(num / 10);
	count += ft_putchar(num % 10 + '0');
	return (count);
}
