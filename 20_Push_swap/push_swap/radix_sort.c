/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 17:06:49 by ribresci          #+#    #+#             */
/*   Updated: 2026/03/10 18:50:47 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

// Trova il numero piu' grande della lista
int	get_max(t_list **b)
{
	int		max;
	t_list	*c;

	if (!b || !*b)
		return (-1);
	c = *b;
	max = INT_MIN;
	while (c)
	{
		if (c->index > max)
			max = c->index;
		c = c->next;
	}
	return (max);
}

// Trova il numero di bit che servono a rappresentare il numero passato
int	get_number(int x)
{
	int	i;

	i = 0;
	while ((x >> i) != 0)
		i++;
	return (i);
}

// Il get_number(ft_lstsize) da il numero di cicli per shiftare tutti i bit
// Il ciclo interno lavora su tutti gli elementi della lista
void	radix_sort(t_list **a, t_list **b)
{
	int		e;
	int		i;
	int		x;
	int		n;

	if (ft_lstsize(*a) <= 1)
		return ;
	e = get_number(get_max(*a));
	n = 0;
	while (e--)
	{
		i = ft_lstsize(a);
		while (i--)
		{
			x = (*a)->index;
			if ((x >> n) & 1)
				rotate(a, NULL, 0);
			else
				push(b, a, 1);
		}
		n++;
		while (*b)
			push(a, b, 0);
	}
}
