/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 17:06:49 by ribresci          #+#    #+#             */
/*   Updated: 2026/02/27 09:54:01 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Pusha tutto da b in a
void	push_back(t_list **a, t_list **b)
{
	while ((*b)->next)
		push(*a, *b, 0);
}

// Trova il numero di bit che servono a rappresentare il numero passato
int	get_number(int x)
{
	int	i;
	int	n;

	i = 1;
	n = 1;
	while (n < x)
	{
		n *= 2;
		i++;
	}
	return (i);
}

// Il get_number(ft_lstsize) da il numero di cicli per shiftare tutti i bit
// Il ciclo interno lavora su tutti gli elementi della lista
void	radix_sort(t_list **a, char *num)
{
	t_list			*b;
	int				e;
	int				i;
	unsigned int	x;

	e = get_number(ft_lstsize(*a));
	b = ft_lstnew(NULL);
	while (e--)
	{
		i = ft_lstsize(*a);
		while (i--)
		{
			x = (*a)->index;
			if (x % 2 == 0)
				push(b, *a, 1);
			else
				rotate(*a, b, 0);
			(*a)->index = x >> 1;
		}
	}
	push_back(a, b);
}
