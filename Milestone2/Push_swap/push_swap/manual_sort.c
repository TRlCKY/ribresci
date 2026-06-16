/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manual_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 12:31:19 by ribresci          #+#    #+#             */
/*   Updated: 2026/03/11 11:24:33 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swap se sono nell'ordine opposto
void	sort2(t_list **a)
{
	if ((*a)->index > (*a)->next->index)
		swap(a, NULL, 0);
}

// Ordina manualmente ogni caso:
// 2, 1, 3
// 1, 3, 2
// 3, 2, 1
// 2, 3, 1
// 3, 1, 2
void	sort3(t_list **a)
{
	t_list	*b;
	t_list	*c;

	b = (*a)->next;
	c = (*a)->next->next;
	if ((*a)->index > b->index && (*a)->index < c->index && b->index < c->index)
		swap(a, NULL, 0);
	if ((*a)->index < b->index && b->index > c->index && (*a)->index < c->index)
	{
		reverse_rotate(a, NULL, 0);
		swap(a, NULL, 0);
	}
	if ((*a)->index > b->index && b->index > c->index)
	{
		rotate(a, NULL, 0);
		swap(a, NULL, 0);
	}
	if ((*a)->index < b->index && b->index > c->index && (*a)->index > c->index)
		reverse_rotate(a, NULL, 0);
	if ((*a)->index > b->index && b->index < c->index && (*a)->index > c->index)
		rotate(a, NULL, 0);
}

void	sort4(t_list **a, t_list **b)
{
	int		e;

	e = find_min(a);
	if (e == 0)
		push(b, a, 1);
	else
	{
		if (e >= 2)
		{
			while (e < 4)
			{
				reverse_rotate(a, NULL, 0);
				e++;
			}
		}
		else
			while (e--)
				rotate(a, NULL, 0);
		push(b, a, 1);
	}
	sort3(a);
	push(a, b, 0);
}

void	sort5(t_list **a, t_list **b)
{
	int		e;

	e = find_min(a);
	if (e == 0)
		push(b, a, 1);
	else
	{
		if (e >= 2)
		{
			while (e < 5)
			{
				reverse_rotate(a, NULL, 0);
				e++;
			}
		}
		else
			while (e--)
				rotate(a, NULL, 0);
		push(b, a, 1);
	}
	sort4(a, b);
	push(a, b, 0);
}

void	manual_sort(t_list **a, t_list **b)
{
	int		i;

	i = ft_lstsize(*a);
	if (i == 2)
		sort2(a);
	if (i == 3)
		sort3(a);
	if (i == 4)
		sort4(a, b);
	if (i == 5)
		sort5(a, b);
}
