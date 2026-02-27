/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 17:06:42 by ribresci          #+#    #+#             */
/*   Updated: 2026/02/27 18:17:54 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Controlla quante posizioni ci sono per raggungere il nodo che contiene x e se
// supera la meta' lo mette negativo per distinguere le operazioni da fare
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
		n = (n - (ft_lstsize(*a) / 2) * -1);
	return (n);
}

// A seconda del segno decide se usare rotate o reverse rotate per poter 
// avere il nodo che contiene x in cima ad a
void	rotate_reverse(t_list **a, t_list **b, int *i)
{
	while (*i != 0)
	{
		if (*i < 0)
		{
			reverse_rotate(*a, *b, 0);
			(*i)++;
		}
		else
		{
			rotate(*a, *b, 0);
			(*i)--;
		}
	}
}

// Ripusha tutto in a
void	send_back(t_list **a, t_list **b)
{
	t_list	*c;

	// funzione che fa cose
	while ((*b)->content)
	{
		c = ft_lstlast(*b);
		if (c->index < (*b)->index)
			reverse_rotate(*b, c, 1);
		push(*a, *b, 0);
	}
	// altra funzione che fa cose
}

// n e' il numero di chunk su cui lavorare finche' non si esauriscono tutti 
// gli elementi. e e' il numero di elementi per chunk e se non sono 
// divisibili si aggiungono all'ultimo chunk
void	chunk_sort(t_list **a)
{
	int		n;
	int		x;
	int		i;
	int		e;
	t_list	**b;

	b = ft_lstnew(NULL);
	n = ft_lstsize(*a) / get_number(ft_lstsize(*a));
	x = ft_lstsize(*a) - 1;
	while (n--)
	{
		e += ft_lstsize(*a) / n;
		while (e--)
		{
			// controllare calcolo visto che n si decrementa
			if (n * e != ft_lstsize(*a) && n == 1)
				e += ft_lstsize(*a) % n;
			i = count_i(*a, x--);
			if (i == 1)
				rotate(*a, *b, 0);
			else
				rotate_reverse(*a, *b, &i);
			push(*b, *a, 1);
		}
		send_back(*a, *b);
	}
}

/*
	Push prende solo il 1o elemento. Non potendo modificare la lista
	si usa il rotate/reverse rotate/swap per spostare l'elemento
	che va pushato nell'altro stack. Non si usa c per pushare ma solo
	a.
*/