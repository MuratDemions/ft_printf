/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musipit <musipit@student.42kocaeli.com.tr> #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-30 09:42:12 by musipit           #+#    #+#             */
/*   Updated: 2026/01/31 11:32:40 by musipit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_putnbr(long n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		n = -n;
		len = 1;
	}
	if (n > 9)
	{
		len = len + ft_putnbr(n / 10);
		if (len == -1)
			return (-1);
	}
	if (ft_putchar((n % 10) + '0') == -1)
		return (-1);
	return (len + 1);
}

int	ft_putuns(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 10)
	{
		len = ft_putuns(n / 10);
		if (len == -1)
			return (-1);
	}
	if (ft_putchar((n % 10) + '0') == -1)
		return (-1);
	return (len + 1);
}

static int	checkandwrite(int format, unsigned long long number)
{
	char	*hex;
	char	*hex_upper;
	int		len;

	len = 0;
	hex = "0123456789abcdef";
	hex_upper = "0123456789ABCDEF";
	if (number >= 16)
		len = len + ft_hex(number / 16, format);
	if (format == 'X')
		len = len + ft_putchar(hex_upper[number % 16]);
	else
		len = len + ft_putchar(hex[number % 16]);
	return (len);
}

int	ft_hex(unsigned long long number, int format)
{
	int	len;

	len = 0;
	if (format == 'p' && number == 0)
	{
		if (ft_putstr("(nil)") == -1)
			return (-1);
		return (5);
	}
	if (format == 'p')
	{
		if (ft_putstr("0x") == -1)
			return (-1);
		format = 'x';
		len = len + 2;
	}
	if (number == 0)
	{
		if (ft_putchar('0') == -1)
			return (-1);
		return (len + 1);
	}
	len = len + checkandwrite(format, number);
	return (len);
}
