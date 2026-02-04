/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musipit <musipit@student.42kocaeli.com.tr> #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-29 11:49:34 by musipit           #+#    #+#             */
/*   Updated: 2026/02/04 17:11:39 by musipit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	checker(char format)
{
	if (format == 'c' || format == 'd' || format == 'i'
		|| format == 'u' || format == '%'
		|| format == 's' || format == 'x'
		|| format == 'X' || format == 'p')
		return (1);
	return (0);
}

static int	router_and_len_returner(va_list arg, char format)
{
	if (format == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (format == 'p')
		return (ft_hex((unsigned long long)va_arg(arg, void *), 'p'));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(arg, int)));
	else if (format == 'u')
		return (ft_putuns(va_arg(arg, unsigned int)));
	else if (format == 'X' || format == 'x')
		return (ft_hex((unsigned long long)va_arg(arg, unsigned int), format));
	else if (format == '%')
		return (ft_putchar('%'));
	else if (format == '\0')
		return (-1);
	return (0);
}

static int	percenter(const char *format, va_list arg, int *i)
{
	int	ret;

	if (format[*i + 1] == '%')
		ret = ft_putchar('%');
	else if (format[*i + 1] == '\0')
		return (-1);
	else if (checker(format[*i + 1]))
		ret = router_and_len_returner(arg, format[*i + 1]);
	else
	{
		if (ft_putchar('%') == -1 || ft_putchar(format[*i + 1]) == -1)
			return (-1);
		ret = 2;
	}
	if (ret == -1)
		return (-1);
	*i += 2;
	return (ret);
}

static int	percent_or_write_router(const char *format, va_list arg)
{
	int		i;
	long	str_len;
	int		ret;

	i = 0;
	str_len = 0;
	while (format[i] && str_len != -1)
	{
		if (format[i] == '%')
		{
			ret = percenter(format, arg, &i);
			if (ret == -1)
				return (-1);
			str_len += ret;
		}
		else
		{
			ret = ft_putchar(format[i++]);
			if (ret == -1)
				return (-1);
			str_len += ret;
		}
	}
	return (str_len);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		str_len;

	if (!format)
		return (-1);
	va_start(arg, format);
	str_len = percent_or_write_router(format, arg);
	va_end(arg);
	return (str_len);
}
