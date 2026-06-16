/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 11:11:58 by ribresci          #+#    #+#             */
/*   Updated: 2026/02/18 11:12:51 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

int	correct(const char *s)
{
	int	i;

	i = 0;
	while (s[i + 3])
	{
		if ((s[i] == '%' && s[i + 1] == '%' && s[i + 2] == '%'
				&& s[i + 3] != '%' && s[i + 3] != 'c' && s[i + 3] != 's'
				&& s[i + 3] != 'p' && s[i + 3] != 'd' && s[i + 3] != 'i'
				&& s[i + 3] != 'u' && s[i + 3] != 'x' && s[i + 3] != 'X'
				&& s[i + 3] != ' ')
			&& (s[i + 4] && s[i + 4] != '%' && s[i + 4] != 'c'
				&& s[i + 4] != 's' && s[i + 4] != 'p' && s[i + 4] != 'd'
				&& s[i + 4] != 'i' && s[i + 4] != 'u' && s[i + 4] != 'x'
				&& s[i + 4] != 'X'))
			return (1);
		i++;
	}
	return (0);
}

int	check(char c, va_list *string)
{
	if (c == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	if (c == 'c')
		return (ft_putchar_fd(va_arg(*string, int), 1));
	if (c == 's')
		return (ft_putstr_fd(va_arg(*string, char *), 1));
	if (c == 'p')
		return (ft_print_pointer(va_arg(*string, void *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr_fd_di(va_arg(*string, int), 1));
	if (c == 'u')
		return (ft_putnbr_fd_u(va_arg(*string, unsigned int), 1));
	if (c == 'x')
		return (ft_print_hex(va_arg(*string, unsigned int), 0));
	if (c == 'X')
		return (ft_print_hex(va_arg(*string, unsigned int), 1));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		x;
	va_list	string;

	va_start(string, s);
	i = 0;
	x = 0;
	if (correct(s))
		return (-1);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
			x += check(s[++i], &string);
		else
		{
			write(1, &s[i], 1);
			x++;
		}
		i++;
	}
	va_end(string);
	return (x);
}
