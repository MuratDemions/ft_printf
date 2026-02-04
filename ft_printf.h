/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libforprintf.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musipit <musipit@student.42kocaeli.com.tr> #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-28 16:37:40 by musipit           #+#    #+#             */
/*   Updated: 2026-01-28 16:37:40 by musipit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_hex(unsigned long long number, int format);
int	ft_putnbr(long n);
int	ft_putuns(unsigned int n);

#endif
