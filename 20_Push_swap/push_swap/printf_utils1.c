/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 11:13:37 by ribresci          #+#    #+#             */
/*   Updated: 2026/02/18 11:15:16 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>

int	ft_print_pointer(void *p)
{
	int				i;
	unsigned long	s;

	i = 0;
	s = (unsigned long)p;
	if (!s)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	i += ft_putstr_fd("0x", 1);
	i += ft_print_hex(s, 0);
	return (i);
}

int	ft_print_hex(unsigned long s, int x)
{
	char	*bob;
	int		n;

	if (x == 0)
		bob = "0123456789abcdef";
	else
		bob = "0123456789ABCDEF";
	n = 0;
	if (s >= 16)
		n += ft_print_hex((s / 16), x);
	n += ft_putchar_fd(bob[s % 16], 1);
	return (n++);
}

int	ft_putchar_fd(int c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

void	ft_putendl_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}

int	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		write(fd, &(s[i]), 1);
		i++;
	}
	return (i);
}
