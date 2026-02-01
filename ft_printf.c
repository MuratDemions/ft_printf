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

static int checker(char format)
{
    if (format == 'c' || format == 'd' || format == 'i' || format == 'u' || format == '%' 
        || format == 's' || format == 'x' || format == 'X' || format == 'p')
        return (1);
    return(0);  
}

static int	f_stringer_and_len_returner(va_list arg, char format)
{
	if (format == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (format == 'p')
		return (ft_hex(va_arg(arg, long long), 'p'));
	else if (format == 'd' || format == 'i' || format == 'u')
		return (ft_putnbr(va_arg(arg, int)));
	else if (format == 'X' || format == 'x')
		return (ft_hex(va_arg(arg, long long), format));
	else if (format == '%' )
		return (ft_putstr("%"));
	else if(format == '\0')
		return (-1);
	return(0);
}
static int  sing_counter(const char *format)
{
    int i;

    i = 0;
    while (format[i] == '%')
    {
        i++;
    }
    if(i % 2 == 1)
        return (-1);
    return (0);
}

int	ft_printf(const char *format, ...)
{
	int	i;
	va_list	arg;
    long total_len;
    long str_len;
    
    str_len = 0;
	i = 0;
	if (!format)
        return (-1);
	va_start(arg, format);
    while (format[i])
    {
	    if(format[i] == '%')
        {
            if(format[i + 1] == '%')
            {
                str_len = sing_counter(format);
                break;
            }
            else if (checker(format[i++]))
            {
                str_len = str_len + f_stringer_and_len_returner(arg, format[i]);
                if(str_len == -1)
                    return (-1);
                total_len = str_len - 1;
            }
        }
        else if(ft_putchar(format[i++]) == -1)
		    return (-1);
        total_len++;
        i++;
    }
    va_end(arg);
    return(str_len);
}

// variadic fonksiyonlar, variadic fonksiyonlar içerisindeki kullanılan şeyler anlamları tanımları vs
// printf dışında variadic fonksiyon örnekleri
