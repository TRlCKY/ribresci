/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 16:24:12 by ribresci          #+#    #+#             */
/*   Updated: 2026/03/11 17:59:29 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

void	freeall(char **mtx)
{
	int	e;

	if (!mtx)
		return ;
	e = 0;
	while (mtx[e])
	{
		free(mtx[e]);
		e++;
	}
	free(mtx);
}

int	count_x(char const *s, char c)
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
	mtx = malloc((count_x(s, c) + 1) * sizeof(char *));
	if (!mtx)
		return (NULL);
	while (e < count_x(s, c))
	{
		y = 0;
		i = go(s, i, c, &y);
		mtx[e] = malloc((y + 1) * sizeof(char));
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

// Converte la stringa con gli elementi nei vari numeri
t_list	*convert_str(char *argv)
{
	int		i;
	char	**mtx;
	t_list	*a;

	mtx = ft_split(argv, ' ');
	if (!mtx)
		return (NULL);
	if (!mtx[0])
	{
		freeall(mtx);
		return (NULL);
	}
	i = 1;
	a = ft_lstnew(ft_atoi(mtx[0]));
	while (mtx[i] != NULL)
	{
		ft_lstadd_back(&a, ft_lstnew(ft_atoi(mtx[i])));
		i++;
	}
	freeall(mtx);
	return (a);
}
