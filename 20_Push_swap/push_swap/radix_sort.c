/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 17:06:49 by ribresci          #+#    #+#             */
/*   Updated: 2026/03/05 16:20:18 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Pusha tutto da b in a
void	push_back(t_list **a, t_list **b)
{
	while (*b)
		push(a, b, 0);
}

// Trova il numero di bit che servono a rappresentare il numero passato
int	get_number(int x)
{
	int	i;
	int	n;

	i = 0;
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
void	radix_sort(t_list **a)
{
	t_list	*b;
	int		e;
	int		i;
	int		x;
	int		n;

	e = get_number(ft_lstsize(*a));
	b = NULL;
	n = 0;
	while (e--)
	{
		i = ft_lstsize(*a);
		while (i--)
		{
			x = (*a)->index;
			if ((x >> n) & 1)
				rotate(a, NULL, 0);
			else
				push(b, a, 1);
		}
		n++;
	}
	push_back(a, b);
}
