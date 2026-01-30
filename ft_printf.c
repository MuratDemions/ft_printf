/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musipit <musipit@student.42kocaeli.com.tr> #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-29 11:49:34 by musipit           #+#    #+#             */
/*   Updated: 2026-01-29 11:49:34 by musipit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libforprintf.h"
#include <stdarg.h>

static  int ft_format(va_list arg, const char format)
{
    if(format == 'c' || format == 'd' || format == 'i' || format == 'u' || format == '%'
		|| format == 's' || format == 'x' || format == 'X' || format == 'p')
        if (format == 'c')
            return (ft_putchar(va_arg(arg, int)));
        else if (format == 's')
		    return (ft_putstr(va_arg(arg, char *)));
    	else if (format == 'p')
		    return (ft_hex(va_arg(arg, long long), 'p'));
	    else if (format == 'd' || format == 'i')
		    return (ft_int(va_arg(arg, int)));
	    else if (format == 'u')
	    	return (ft_putnbr(va_arg(arg, unsigned int)));
	    else if (format == 'X' || format == 'x')
		    return (ft_hex(va_arg(arg, long long), format));
	    else if (format == '%')
		    return (ft_putchar('%'));
    else if (format == '\0')
        return (-1);
    return(0);
    
}

int ft_printf(const char *format, ...)
{
    int i;
    va_list arg;

    i = 0;
    va_start(arg, format);
    if(!format)
        return (-1);
    while (format[i])
    {
        if(ft_format(arg, format) == -1)
        {
            return (-1);
        }
        else
            ft_putchar(format[i]);
        i++;
    }
    
    va_end(arg);
    return(-1);
}
