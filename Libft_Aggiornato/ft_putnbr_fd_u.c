/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 09:57:17 by ribresci          #+#    #+#             */
/*   Updated: 2026/01/16 15:36:17 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>
/*

int	power(int a, int b);
int	count(int n);
int	ft_putnbr_fd(int n, int fd);

int	main()
{
	int	fd;

	fd = 1;
	ft_putnbr_fd(INT_MAX, fd);
	ft_putnbr_fd(INT_MIN, fd);
	ft_putnbr_fd(0, fd);
	ft_putnbr_fd(100, fd);
	ft_putnbr_fd(-10, fd);
	return (0);
}
*/
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
