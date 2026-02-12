/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 11:07:01 by ribresci          #+#    #+#             */
/*   Updated: 2025/12/18 16:30:25 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
/*
#include <stdio.h>

size_t	skip1(const char *s1, const char *set);
size_t	skip2(const char *s1, const char *set, size_t i);
char	*ft_strtrim(const char *s1, const char *set);

int	main()
{
	const char	*s1 = " lorem vxcvbn amet";
	const char	*set = " let";

	printf("%s\n", s1);
	printf("%s\n", ft_strtrim(s1, set));
	return (0);
}
*/

size_t	skip1(const char *s1, const char *set)
{
	size_t	i;
	size_t	j;
	size_t	x;
	size_t	sz1;
	size_t	sz2;

	sz1 = ft_strlen(s1);
	sz2 = ft_strlen(set);
	i = 0;
	while (i < sz1)
	{
		j = 0;
		x = 0;
		while (j < sz2)
			if (s1[i] && set[j] && s1[i] == set[j++])
				x++;
		if (!x)
			break ;
		i++;
	}
	return (i);
}

size_t	skip2(const char *s1, const char *set, size_t i)
{
	size_t	j;
	size_t	x;
	size_t	e;

	e = ft_strlen(s1) - 1;
	while (e > i)
	{
		j = 0;
		x = 0;
		while (j < ft_strlen(set))
		{
			if (s1[e] == set[j])
				x++;
			j++;
		}
		if (!x)
			break ;
		e--;
	}
	return (e);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*s2;
	size_t	i;
	size_t	x;
	size_t	y;

	if (!s1 && !set)
		return (NULL);
	x = ft_strlen(s1);
	i = skip1(s1, set);
	if (i == x)
		i = 0;
	y = x - skip2(s1, set, i);
	if (i == 0 && y == x)
	{
		s2 = (char *)ft_calloc(1, sizeof(char));
		return (s2);
	}
	s2 = (char *)ft_calloc(x - i - y + 2, sizeof(char));
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, &s1[i], x - i - y + 2);
	return (s2);
}
