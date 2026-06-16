/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 11:31:43 by ribresci          #+#    #+#             */
/*   Updated: 2026/03/10 17:33:57 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <limits.h>
#include <string.h>

void	rotate2(t_list **a)
{
	t_list	*c;

	c = *a;
	*a = (*a)->next;
	c->next = NULL;
	ft_lstadd_back(a, c);
}

// Sposta il primo elemento nell'ultima posizione
void	rotate(t_list **a, t_list **b, int x)
{
	if (a && *a && x == 0 && ft_lstsize(*a) >= 2)
	{
		rotate2(a);
		ft_printf("ra\n");
	}
	if (b && *b && x == 1 && ft_lstsize(*b) >= 2)
	{
		rotate2(b);
		ft_printf("rb\n");
	}
	if (a && *a && b && *b && x == 2
		&& ft_lstsize(*a) >= 2 && ft_lstsize(*b) >= 2)
	{
		rotate2(a);
		rotate2(b);
		ft_printf("rr\n");
	}
}

void	reverse_rotate2(t_list **b)
{
	t_list	*c;
	t_list	*d;

	if (!b || !*b || !(*b)->next)
		return ;
	c = NULL;
	d = *b;
	while (d->next)
	{
		c = d;
		d = d->next;
	}
	c->next = NULL;
	d->next = *b;
	*b = d;
}

// Sposta l'ultimo elemento in prima posizione
void	reverse_rotate(t_list **a, t_list **b, int x)
{
	if (a && *a && x == 0 && ft_lstsize(*a) > 1)
	{
		reverse_rotate2(a);
		ft_printf("rra\n");
	}
	if (b && *b && x == 1 && ft_lstsize(*b) > 1)
	{
		reverse_rotate2(b);
		ft_printf("rrb\n");
	}
	if (a && *a && b && *b && x == 2
		&& ft_lstsize(*a) > 1 && ft_lstsize(*b) > 1)
	{
		reverse_rotate2(a);
		reverse_rotate2(b);
		ft_printf("rrr\n");
	}
}
