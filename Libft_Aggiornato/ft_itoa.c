/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 16:46:39 by ribresci          #+#    #+#             */
/*   Updated: 2025/12/17 17:14:40 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "libft.h"
/*
#include <stdio.h>

int		power(int a, int b);
int		count(int *n);
char	*ft_itoa(int n);

int main(void)
{
	printf("s1: %s\n\n", ft_itoa(INT_MAX));
	printf("s2: %s\n\n", ft_itoa(INT_MIN));
	printf("s3: %s\n\n", ft_itoa(0));
	printf("s4: %s\n\n", ft_itoa(1000));
	printf("s5: %s\n\n", ft_itoa(-1));
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

int	count(int *n)
{
	int	x;
	int	i;

	i = *n;
	x = 0;
	if (*n == INT_MIN)
	{
		x = 11;
		return (x);
	}
	if (*n < 0)
		x++;
	if (i == 0)
		x++;
	while (i != 0)
	{
		i /= 10;
		x++;
	}
	return (x);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		n1;
	int		i;
	int		x;

	x = count(&n);
	i = 0;
	s = ft_calloc((x + 1), sizeof(char));
	if (!s)
		return (NULL);
	if (n < 0)
	{
		s[i++] = '-';
		x--;
	}
	while (x > 0)
	{
		n1 = n / power(10, (x - 1));
		n -= (n1 * power(10, ((x) - 1)));
		if (n1 < 0)
			n1 = -n1;
		s[i++] = n1 + '0';
		x--;
	}
	return (s);
}
