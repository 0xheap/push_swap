/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdessel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 21:58:20 by abdessel          #+#    #+#             */
/*   Updated: 2025/11/04 21:58:20 by abdessel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handle_format(char format, va_list args, int *is_valid)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (format == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		count += ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		count += ft_puthex(va_arg(args, unsigned int), format);
	else if (format == 'p')
		count += ft_putpointer(va_arg(args, void *));
	else if (format == '%')
		count += ft_putchar('%');
	else
	{
		*is_valid = 0;
		count += ft_putchar('%');
		count += ft_putchar(format);
	}
	return (count);
}

static int	ft_handle_trailing_percent(int is_valid, int count, va_list args)
{
	if (is_valid)
	{
		va_end(args);
		return (-1);
	}
	else
	{
		count += ft_putchar('%');
		va_end(args);
		return (count);
	}
}

static int	ft_process_format(const char *format, va_list args, int *is_valid)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i])
				count += ft_handle_format(format[i], args, is_valid);
			else
				return (ft_handle_trailing_percent(*is_valid, count, args));
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		is_valid;
	int		result;

	if (!format)
		return (-1);
	va_start(args, format);
	is_valid = 1;
	result = ft_process_format(format, args, &is_valid);
	va_end(args);
	return (result);
}
