/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 11:15:32 by ribresci          #+#    #+#             */
/*   Updated: 2026/02/18 11:18:37 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>
#include <limits.h>

int	power(int a, int b)
{
	int	c;

	c = a;
	if (b == 0)
		c = 1;
	if (b == 1)
		c = 10;
	while (b > 1)
	{
		c *= a;
		b--;
	}
	return (c);
}

int	count(unsigned int n)
{
	int	x;

	x = 0;
	if (n == 0)
		x++;
	if (n < 0)
		n += UINT_MAX;
	while (n != 0)
	{
		n /= 10;
		x++;
	}
	return (x);
}

int	ft_putnbr_fd_u(unsigned int n, int fd)
{
	unsigned int	n1;
	int				i;
	int				e;
	int				x;

	i = 0;
	e = count(n);
	x = 0;
	if (e == 0)
		write(fd, "0", 1);
	while (e > 0)
	{
		n1 = n / power(10, (e - 1));
		n = n - (n1 * power(10, (e - 1)));
		if (n1 < 0)
			n1 = -n1;
		n1 += '0';
		write(fd, &n1, 1);
		e--;
		x++;
	}
	return (x);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	n1;
	int	i;
	int	e;

	i = 0;
	e = count(n);
	if (e == 0)
		write(fd, "0", 1);
	if (n < 0)
		write(fd, "-", 1);
	while (e > 0)
	{
		n1 = n / power(10, (e - 1));
		n = n - (n1 * power(10, (e - 1)));
		if (n1 < 0)
			n1 = -n1;
		n1 += '0';
		write(fd, &n1, 1);
		e--;
	}
}

int	ft_putnbr_fd_di(int n, int fd)
{
	int	n1;
	int	i;
	int	e;
	int	x;

	i = 0;
	e = count1(n, 1);
	x = 0;
	if (n < 0)
		x++;
	if (n == 0)
		return (1);
	while (e > 0)
	{
		n1 = n / power1(10, (e - 1));
		n = n - (n1 * power1(10, (e - 1)));
		if (n1 < 0)
			n1 = -n1;
		n1 += '0';
		write(fd, &n1, 1);
		e--;
		x++;
	}
	return (x);
}
