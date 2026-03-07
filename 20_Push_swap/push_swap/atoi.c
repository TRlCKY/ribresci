/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 16:46:39 by ribresci          #+#    #+#             */
/*   Updated: 2026/03/07 10:44:27 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

unsigned int	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	e;

	i = 0;
	e = 0;
	if (src && dest)
	{
		while (src[e])
			e++;
		if (size > 0)
		{
			while (src[i] != '\0' && i < size - 1)
			{
				dest[i] = src[i];
				i++;
			}
			dest[i] = '\0';
		}
	}
	return (e);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (i == n)
		return (0);
	return (s1[i] - s2[i]);
}

// Controlla che il numero sia nei limiti di int restituendo 1 se non lo e'
int	check_limit(const char *str, int sign)
{
	int		i;
	char	*max;
	char	*min;

	i = 0;
	max = "2147483647";
	min = "2147483648";
	if (ft_strlen(str) > 10)
		return (1);
	if (ft_strlen(str) < 10)
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	i = 0;
	if (str[i] == '-' || str[i] == '+' || str[i] == '0')
		return (1);
	if (ft_strncmp(str, max, 10) > 0 && sign == 1)
		return (1);
	if (ft_strncmp(str, min, 10) > 0 && sign == -1)
		return (1);
	return (0);
}

// Converte la stringa in un intero, controllando che il numero sia un intero
// e che sia valido
int	ft_atoi(const char *str)
{
	int			i;
	long long	n;
	int			sign;

	i = 0;
	n = 0;
	sign = 1;
	if (!str)
		return (0);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	if ((str[i] == 45 || str[i] == 43) && str[i + 1] >= 48 && str[i + 1] <= 57)
		return (0);
	if (check_limit(&str[i], sign))
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
		n = (n * 10) + (str[i++] - '0');
	if (str[i])
		return (0);
	return (n * sign);
}
