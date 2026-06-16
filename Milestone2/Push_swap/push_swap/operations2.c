/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 17:26:55 by ribresci          #+#    #+#             */
/*   Updated: 2026/03/10 17:27:54 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <limits.h>
#include <string.h>

// Scambia i primi 2 elementi
void	swap(t_list	**a, t_list **b, int x)
{
	t_list	*c;

	if ((x == 0 || x == 2) && a && (*a) && (*a)->next)
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
	if ((x == 1 || x == 2) && b && (*b) && (*b)->next)
	{
		c = (*b)->next;
		(*b)->next = c->next;
		c->next = *b;
		*b = c;
		if (x == 1)
			ft_printf("sb\n");
	}
}

// Sposta il primo elemento di (b) in cima ad (a)
void	push(t_list **a, t_list **b, int x)
{
	t_list	*c;

	if (!b || !*b)
		return ;
	if (x == 0)
		ft_printf("pa\n");
	else
		ft_printf("pb\n");
	c = *b;
	*b = (*b)->next;
	c->next = *a;
	*a = c;
}
