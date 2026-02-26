/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 17:06:42 by ribresci          #+#    #+#             */
/*   Updated: 2026/02/26 17:21:03 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_i(t_list **a, int x)
{
	t_list	*c;
	int		n;

	c = *a;
	n = 0;
	while (c->next)
	{
		if (c->index != x)
			n++;
		else
			return (n);
		c = c->next;
	}
	if (n > ft_lstsize(*a) / 2)
		n = (n - (ft_lstsize(*a) / 2)* -1);
	return (n);
}

rotate_reverse(t_list **a, t_list **b, int *i)
{
	if (*i < 0)
	{
		reverse_rotate(*a, *b, 0);
		*i++;
	}
	else
	{
		rotate(*a, *b, 0);
		*i--;
	}
}

void	chunk_sort(t_list **a)
{
	int		n;
	int		x;
	int		i;
	t_list	**b;

	b = ft_lstnew(NULL);
	n = ft_lstsize(*a) / get_number(ft_lstsize(*a));
	x = ft_lstsize(*a) - 1;
	while (n--)
	{
		i = count_i(*a, x);
		x--;
		if (i == 1)
			rotate(*a, *b, 0);
		else
			while (i != 0)
				rotate_reverse(*a, *b, &i);
		push(*b, *a, 0);
	}
}

/*
	Push prende solo il 1o elemento. Non potendo modificare la lista
	si usa il rotate/reverse rotate/swap per spostare l'elemento
	che va pushato nell'altro stack. Non si usa c per pushare ma solo
	a.
*/