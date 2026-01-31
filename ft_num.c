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
	if (n > 9)
	{
		len = ft_putnbr(n / 10);
		if (len == -1)
			return (-1);
	}
	if (ft_putchar((n % 10 + '0')) == -1)
		return (-1);
	return (len + 1);
}

int	ft_hex(long long number, int format)
{
	int		len;
	char	*hex;
	char	*hex_upper;

	hex = "0123456789abcdef";
	hex_upper = "0123456789ABCDEF";
	len = 0;
	if (number == '\0')
		return (-1);
	if (format == 'p')
	{
		ft_putstr("0x");
		format = 0;
		len = len + 2;
	}
	if (number >= 16)
		len = len + ft_hex(number / 16, format);
	if (format == 'X')
		ft_putchar(hex_upper[number]);
	else
		ft_putchar(hex[number]);
	return (len);
}
