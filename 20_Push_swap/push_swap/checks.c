/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:16:04 by ribresci          #+#    #+#             */
/*   Updated: 2026/03/02 10:18:27 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Controlla che tutti gli argomenti siano diversi
int	check_same(char *argv)
{
	int	i;
	int	e;

	i = 1;
	e = 1;
	while (argv[i])
	{
		while (argv[e])
		{
			if (argv[i] != argv[e] && i != e)
				e++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}

// Controlla che gli elementi siano gia' in ordine
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

int	check_all(t_list	**argv)
{
	if (is_in_order(*argv) && check_same(*argv))
		return (0);
	else
		return (1);
}
