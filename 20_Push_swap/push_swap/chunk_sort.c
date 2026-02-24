/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 17:06:42 by ribresci          #+#    #+#             */
/*   Updated: 2026/02/20 18:03:38 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_list **a, int limit)
{
	t_list	*c;
	int		max;
	int		i;

	c = *a;
	max = 0;
	while (c->next)
	{
		i = c->index;
		if (i > max && i < limit)
			max = i;
	}
	return (max);
}

void	chunk_sort(t_list **a)
{
	int		e;
	int		n;
	int		x;
	t_list	*b;
	t_list	*c;

	b = ft_lstnew(NULL);
	c = *a;
	e = get_number(ft_lstsize(c));
	n = ft_lstsize(c) / e;
	x = ft_lstsize(c);
	while (n--)
	{
		c = *a;
		while (c->next)
		{
			if (c->index == find_max(c, x))
			{
				push(c, b, 0);
				x--;
			}
			c = c->next;
		}
		
	}
}
