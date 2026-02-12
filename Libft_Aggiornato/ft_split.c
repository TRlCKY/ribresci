/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:49:03 by ribresci          #+#    #+#             */
/*   Updated: 2025/12/18 18:47:40 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
/*
#include <stdio.h>

int		count(char const *s, char c);
int		go(char const *s, int i, char c, int *y);
char	**ft_split(char const *s, char c);

int	main(void)
{
	char const	*s = "Trip ";
	char		c = ' ';
	int			i;
	char		**mtx;

	mtx = ft_split(s, c);
	i = 0;
	if (mtx)
	{
		while (*mtx != NULL)
		{
			printf("%s\n", *mtx);
			mtx++;
		}
	}
	else
		printf("f\n");
	return (0);
}
*/
void	freeall(char **mtx)
{
	int	e;

	e = 0;
	while (e)
	{
		free(mtx[e]);
		e--;
	}
	free(mtx);
}

int	count(char const *s, char c)
{
	int	x;
	int	i;

	i = 0;
	x = 0;
	if (s[0] == '\0')
		return (0);
	if (c == '\0' && s[0])
		return (1);
	if (s[i] != c)
		x++;
	while (s[i] && s[i + 1])
	{
		if ((char)s[i] == c && ((char)s[i + 1] != '\0'
				&& (char)s[i + 1] != c))
			x++;
		i++;
	}
	return (x);
}

int	go(char const *s, int i, char c, int *y)
{
	if (s[i] == c)
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			i++;
			*y = *y + 1;
		}
	}
	else
	{
		while (s[i] && s[i] != c)
		{
			i++;
			*y = *y + 1;
		}
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		e;
	int		y;
	char	**mtx;

	e = 0;
	i = 0;
	mtx = ft_calloc((count(s, c) + 1), sizeof(char *));
	if (!mtx)
		return (NULL);
	while (e < count(s, c))
	{
		y = 0;
		i = go(s, i, c, &y);
		mtx[e] = ft_calloc(y + 1, sizeof(char));
		if (!mtx[e])
		{
			freeall(mtx);
			return (NULL);
		}
		ft_strlcpy(mtx[e++], (char *)(&s[i - y]), (y + 1));
	}
	mtx[e] = NULL;
	return (mtx);
}
