/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 11:31:43 by ribresci          #+#    #+#             */
/*   Updated: 2026/03/06 18:51:27 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <limits.h>
#include <string.h>

void	swap(t_list	**a, t_list **b, int x)
{
	t_list	*c;

	if ((x == 0 || x == 2) && (*a) && (*a)->next)
	{
		c = (*a)->next;
		(*a)->next = c->next;
		c->next = *a;
		*a = c;
		if (x == 0)
			ft_printf("sa\n");
		else
			ft_printf("ss\n");
	}
	if ((x == 1 || x == 2) && (*b) && (*b)->next)
	{
		ft_printf("sb\n");
		c = (*b)->next;
		(*b)->next = c->next;
		c->next = *b;
		*b = c;
		if (x == 1)
			ft_printf("sa\n");
	}
}

void	push(t_list **a, t_list **b, int x)
{
	t_list	*c;

	if (!(*b))
		return ;
	if (x == 0)
		ft_printf("pa\n");
	if (x == 1)
		ft_printf("pb\n");
	c = *b;
	*b = (*b)->next;
	ft_lstadd_front(a, c);
}

void	rotate(t_list **a, t_list **b, int x)
{
	t_list	*c;

	if ((x == 0 || x == 2) && ft_lstsize(*a) >= 2)
	{
		c = *a;
		*a = (*a)->next;
		c->next = NULL;
		ft_lstadd_back(a, c);
		if (x == 0)
			ft_printf("ra\n");
		else
			ft_printf("rr\n");
	}
	if ((x == 1 || x == 2) && ft_lstsize(*b) >= 2)
	{
		c = *b;
		*b = (*b)->next;
		c->next = NULL;
		ft_lstadd_back(b, c);
		if (x == 1)
			ft_printf("rb\n");
	}
}

void	reverse_rotate2(t_list **b)
{
	t_list	*c;
	t_list	*d;
	int		i;

	if (ft_lstsize(*b) <= 1)
		return ;
	ft_printf("rrr\n");
	i = ft_lstsize(*b) - 2;
	c = ft_lstlast(*b);
	d = *b;
	while (i--)
		d = d->next;
	d->next = NULL;
	ft_lstadd_back(b, c);
}

void	reverse_rotate(t_list **a, t_list **b, int x)
{
	t_list	*c;
	t_list	*d;
	int		i;

	if (ft_lstsize(*a) <= 1)
		return ;
	if (x == 0)
		ft_printf("rra\n");
	if (x == 1)
		ft_printf("rrb\n");
	i = ft_lstsize(*a) - 2;
	c = ft_lstlast(*a);
	d = *a;
	while (i--)
		d = d->next;
	d->next = NULL;
	ft_lstadd_back(a, c);
	if (x == 2 && ft_lstsize(*b) >= 2)
		reverse_rotate2(b);
}
