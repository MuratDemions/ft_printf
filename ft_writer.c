/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musipit <musipit@student.42kocaeli.com.tr> #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-02-03 19:41:34 by musipit           #+#    #+#             */
/*   Updated: 2026/02/03 19:41:55 by musipit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	checker(char format)
{
	if (format == 'c' || format == 'd' || format == 'i'
		|| format == 'u' || format == '%'
		|| format == 's' || format == 'x'
		|| format == 'X' || format == 'p')
		return (1);
	return (0);
}

int	f_stringer_and_len_returner(va_list arg, char format)
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
