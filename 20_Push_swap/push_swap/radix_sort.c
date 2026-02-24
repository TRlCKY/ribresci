/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 17:06:49 by ribresci          #+#    #+#             */
/*   Updated: 2026/02/24 12:45:43 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_back(t_list **a, t_list **b)
{
	while ((*b)->next)
	{
		push(a, *b, 0);
		*b = (*b)->next;
	}
}

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

void	radix_sort(t_list **a)
{
	t_list			*c;
	t_list			*b;
	int				e;
	unsigned int	x;

	e = get_number(ft_lstsize(*a));
	b = ft_lstnew(NULL);
	while (e--)
	{
		c = *a;
		while (c->next)
		{
			x = c->index;
			if (x == 0)
				push(b, a, 1);
			else
				rotate(a, b, 0);
			c->index = x >> 1;
			c = c->next;
		}
	}
	push_back(a, b);
}
