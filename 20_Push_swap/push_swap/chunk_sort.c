/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 15:14:40 by ribresci          #+#    #+#             */
/*   Updated: 2026/03/10 17:37:30 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

// Se il valore piu' alto non si trova in prima/ultima posizione lo trova e lo 
// mette o in prima o in ultima posizione
int	find_max(t_list **b)
{
	int		max;
	int		x;
	int		i;
	t_list	*c;

	if (!b || !*b)
		return (-1);
	if (ft_lstsize(*b) == 1)
		return (0);
	c = *b;
	max = -1;
	x = 0;
	i = 0;
	while (c)
	{
		if (c->index > max)
		{
			max = c->index;
			x = i;
		}
		c = c->next;
		i++;
	}
	return (x);
}

// Ripusha tutto in a mandando prima il piu grande, sistemando le posizioni se
// non si trova in cima o in fondo alla lista
void	send_back(t_list **a, t_list **b)
{
	int		i;
	int		e;
	int		size;

	while (*b)
	{
		i = find_max(b);
		e = ft_lstsize(*b) / 2;
		size = ft_lstsize(*b);
		if (i == 0)
			push(a, b, 0);
		else
		{
			if (i < e)
				while (i--)
					rotate(NULL, b, 1);
			else
				while (i++ < size)
					reverse_rotate(NULL, b, 1);
			push(a, b, 0);
		}
	}
}

int	find_max_min(t_list **a, int max, int min)
{
	int		i;
	t_list	*c;

	i = 0;
	c = *a;
	while (c)
	{
		if (c->index >= min && c->index <= max)
			return (i);
		i++;
		c = c->next;
	}
	return (-1);
}

// Trova il primo elemento appartenente al chunk tra max e min e decide se 
// usare ra o rra per portare quell'elemento in cima alla lista.
int	find_chunk(t_list **a, int size, int chunk_size)
{
	int		max;
	int		min;
	int		i;
	int		e;

	if (!a || !*a)
		return (0);
	e = ft_lstsize(*a);
	max = size;
	min = size - chunk_size + 1;
	i = find_max_min(a, max, min);
	if (i < 0)
		return (0);
	if (i == 0)
		return (1);
	if (i >= e / 2)
		while (i++ < e)
			reverse_rotate(a, NULL, 0);
	else
		while (i--)
			rotate(a, NULL, 0);
	return (1);
}

// n e' il numero di chunk su cui lavorare finche' non si esauriscono tutti 
// gli elementi del chunk. chunk_size e' il numero di elementi per chunk e il
// resto  della divisione viene aggiunto all'ulyimo chunk. Poi si pusha 
// l'elemento in B. Se l'elemento e' nella parte dei numeri piu' piccoli viene
// messo in fondo a B. Si inizia dagli elementi piu' piccoli e poi a salire.
// i valori con 2 nel nome rimangono fissi, gli altri variano.
void	chunk_sort(t_list **a, t_list **b, int size, int n)
{
	int		size2;
	int		chunk_size;
	int		chunk_size2;

	size2 = size - 1;
	while (n--)
	{
		chunk_size = size / 5;
		if (n == 0)
			chunk_size = size;
		chunk_size2 = chunk_size;
		while (chunk_size > 0)
		{
			if (!find_chunk(a, size2, chunk_size2))
				break ;
			push(b, a, 1);
			if (*b && (*b)->index <= size2 - (chunk_size2 / 2)
				&& (*b)->index >= size2 - chunk_size2 + 1)
				rotate(NULL, b, 1);
			chunk_size--;
		}
		size -= (chunk_size2 - chunk_size);
		size2 -= (chunk_size2 - chunk_size);
	}
	send_back(a, b);
}
