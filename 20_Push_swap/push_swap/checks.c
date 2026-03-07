/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:16:04 by ribresci          #+#    #+#             */
/*   Updated: 2026/03/07 12:06:27 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Controlla che tutti gli argomenti siano diversi
// Restituisce 0 se non lo sono, 1 se lo sono
int	has_duplicates(t_list **a)
{
	t_list	*b;
	t_list	*c;

	b = *a;
	while (b)
	{
		c = b->next;
		while (c)
		{
			if (b->content == c->content)
				return (1);
			c = c->next;
		}
		b = b->next;
	}
	return (0);
}

// Controlla che gli elementi siano gia' in ordine
// Restituisce 0 se non lo sono, 1 se lo sono
int	is_in_order(t_list **a)
{
	t_list	*b;
	t_list	*c;

	b = *a;
	c = b->next;
	while (c)
	{
		if (b->index > c->index)
			return (0);
		b = b->next;
		c = c->next;
	}
	return (1);
}

// Resituisce la lunghezza della stringa
int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
			i++;
	}
	return (i);
}
