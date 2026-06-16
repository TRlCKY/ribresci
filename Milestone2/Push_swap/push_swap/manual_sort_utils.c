/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manual_sort_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 12:40:35 by ribresci          #+#    #+#             */
/*   Updated: 2026/03/11 16:32:34 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_list **a)
{
	int		min;
	t_list	*b;
	int		i;
	int		e;

	min = (*a)->index;
	b = *a;
	b = b->next;
	i = 1;
	e = 0;
	while (b)
	{
		if (min > b->index)
		{
			min = b->index;
			e = i;
		}
		b = b->next;
		i++;
	}
	return (e);
}

// Resituisce la lunghezza della stringa
int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
			i++;
	}
	return (i);
}
