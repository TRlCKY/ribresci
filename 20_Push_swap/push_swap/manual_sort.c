/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manual_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 12:31:19 by ribresci          #+#    #+#             */
/*   Updated: 2026/02/26 18:41:21 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_in_order(t_list **a)
{
	t_list	*b;
	t_list	*c;

	b = *a;
	c = *a;
	c = c->next;
	while (c->next)
	{
		if (b->index > c->index)
			return (0);
		b = b->next;
		c = c->next;
	}
	return (1);
}

void	manual_sort(t_list **a)
{
	t_list	*b;
	t_list	*c;
	int		i;

	i = ft_lstsize(a);
	b = *a;
	c = *a;
	c = c->next;
	if (!is_in_order(b))
		return ;
	else
	{
		while (i--)
		{
			if (b->index > c->index)
				rotate(b, b, 0);
			b = b->next;
			c = c->next;
		}
	}
}
