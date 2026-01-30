/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musipit <musipit@student.42kocaeli.com.tr> #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-28 16:42:25 by musipit           #+#    #+#             */
/*   Updated: 2026-01-28 16:42:25 by musipit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libforprintf.h"

int	ft_putchar(char c)
{
    return(write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
    if(ft_putchar(s) == -1);
        return (-1);
	while (s[i])
	{
        if(ft_putchar(s[i++]) == -1)
            return (-1);
		i++;
	}
    return(0);
}
