/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musipit <musipit@student.42kocaeli.com.tr> #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-29 11:49:34 by musipit           #+#    #+#             */
/*   Updated: 2026/01/31 11:59:55 by musipit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	percent_counter(const char *format)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			j = i;
			count = 0;
			while (format[j] == '%')
			{
				count++;
				j++;
			}
			if (format[j] == '\0' && (count % 2 == 1))
				return (-1);
			i = j;
		}
		else
			i++;
	}
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
		ret = f_stringer_and_len_returner(arg, format[*i + 1]);
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

static int	writer(const char *format, va_list arg)
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
	if (percent_counter(format) == -1)
		return (-1);
	va_start(arg, format);
	str_len = writer(format, arg);
	va_end(arg);
	return (str_len);
}
