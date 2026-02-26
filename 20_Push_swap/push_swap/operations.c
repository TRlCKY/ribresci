/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 11:31:43 by ribresci          #+#    #+#             */
/*   Updated: 2026/02/26 12:19:32 by ribresci         ###   ########.fr       */
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

	if (ft_lstsize(a) <= 1)
		return ;
	if (x == 0)
		ft_printf("sa\n");
	if (x == 1)
		ft_printf("sb\n");
	c = (*a)->next;
	(*a)->next = c->next;
	c->next = a;
	if (x == 2)
	{
		if (ft_lstsize(b) <= 1)
			return ;
		ft_printf("ss\n");
		c = (*b)->next;
		(*b)->next = c->next;
		c->next = b;
	}
}

void	push(t_list **a, t_list **b, int x)
{
	t_list	*c;

	if (ft_lstsize(b) <= 1)
		return ;
	if (x == 0)
		ft_printf("pa\n");
	if (x == 1)
		ft_printf("pb\n");
	c = *b;
	*b = (*b)->next;
	ft_lstadd_front(a, b);
}

void	rotate(t_list **a, t_list **b, int x)
{
	t_list	*c;

	if (ft_lstsize(a) <= 1)
		return ;
	if (x == 0)
		ft_printf("ra\n");
	if (x == 1)
		ft_printf("rb\n");
	c = *a;
	*a = (*a)->next;
	ft_lstadd_back(a, c);
	if (x == 2)
	{
		if (ft_lstsize(b) <= 1)
			return ;
		ft_printf("rr\n");
		c = *b;
		*b = (*b)->next;
		ft_lstadd_back(b, c);
	}
	free (c);
}

void	reverse_rotate2(t_list **b)
{
	t_list	*c;
	t_list	*d;
	int		i;

	if (ft_lstsize(*b) <= 1)
		return ;
	ft_printf("rrr\n");
	i = ft_lstsize(*b) - 1;
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
	i = ft_lstsize(*a) - 1;
	c = ft_lstlast(*a);
	d = *a;
	while (i--)
		d = d->next;
	d->next = NULL;
	ft_lstadd_back(a, c);
	if (x == 2)
		reverse_rotate2(b);
}
