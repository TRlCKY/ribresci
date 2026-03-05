/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 10:14:44 by ribresci          #+#    #+#             */
/*   Updated: 2026/03/05 16:26:08 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Ordina l'array dopo aver ricevuto i valori contenuti nella lista
unsigned char	*order(unsigned char **b, int i)
{
	int				e;
	int				k;
	unsigned char	d;

	k = 0;
	e = 0;
	while (e < i)
	{
		while (k < i - 1)
		{
			if (b[k] > b[k + 1])
			{
				d = b[k];
				b[k] = b[k + 1];
				b[k + 1] = d;
			}
			k++;
		}
		e++;
	}
	return (b);
}

// Riempie l'array da ordinare con gli elementi della lista
unsigned char	*fill_array(unsigned char *b, t_list **a)
{
	int		e;
	t_list	*c;
	int		i;

	i = ft_lstsize(*a);
	c = *a;
	e = 0;
	while (c->next)
	{
		b[e++] = c->content;
		c = c->next;
	}
	b = order(b, i);
	return (b);
}

// Indicizza la lista
void	*index(t_list **a, int i)
{
	unsigned char	*b;
	t_list			*c;
	int				e;

	b = malloc(sizeof(unsigned char) * (i + 1));
	if (!b)
		return (NULL);
	fill_array(b, a);
	c = *a;
	while (c->next)
	{
		e = 0;
		while (e < i)
		{
			if (b[e] == (unsigned char)c->content)
				c->index = e++;
		}
		c = c->next;
	}
}

int	main(int argc, char **argv)
{
	t_list	*a;
	int		i;

	if (check_all(argv))
		return ;
	a = ft_lstnew(argv[++argc]);
	while (argv[++argc])
		ft_lstadd_back(a, argv[argc]);
	i = ft_lstsize(a);
	index(a, i);
	if (i >= 2 && i <= 5)
		manual_sort(a);
	if (i > 5 && i <= 100)
		chunk_sort(a, i);
	if (i > 100)
		radix_sort(a);
}
