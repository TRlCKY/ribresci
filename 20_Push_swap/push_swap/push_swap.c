/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 10:14:44 by ribresci          #+#    #+#             */
/*   Updated: 2026/03/09 16:40:48 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Ordina l'array dopo aver ricevuto i valori contenuti nella lista
int	*order(int *b, int i)
{
	int	e;
	int	k;
	int	d;

	k = 0;
	e = 0;
	while (e < i - 1)
	{
		k = 0;
		while (k < i - 1 - e)
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
int	*fill_array(int *b, t_list **a)
{
	int		e;
	t_list	*c;
	int		i;

	i = ft_lstsize(*a);
	c = *a;
	e = 0;
	while (c)
	{
		b[e++] = c->content;
		c = c->next;
	}
	b = order(b, i);
	return (b);
}

// Indicizza la lista basandosi sull'array creato
void	set_index(t_list **a, int i)
{
	int		*b;
	t_list	*c;
	int		e;

	b = malloc(sizeof(int) * i);
	if (!b)
		return ;
	fill_array(b, a);
	c = *a;
	while (c)
	{
		e = 0;
		while (e < i)
		{
			if (b[e] == c->content)
			{
				c->index = e;
				break ;
			}
			e++;
		}
		c = c->next;
	}
	free(b);
}

// A seconda del numero di elementi verra' usato un algoritmo di ordinamento
// oppure un altro
int	man_rad_chun(t_list **a, int i)
{
	if (i >= 2 && i <= 5)
		manual_sort(a);
	if (i > 5 && i <= 100)
		chunk_sort(a, i, 5);
	if (i > 100)
		radix_sort(a);
	return (0);
}

// Dopo i vari controlli e aver preso i valori crea la lista con cui
// verranno ordinati i valori. 
int	main(int argc, char **argv)
{
	t_list	*a;
	int		e;

	e = 1;
	if (argc == 1)
		return (0);
	if (argc == 2)
		a = convert_str(argv[1]);
	else
	{
		a = ft_lstnew(ft_atoi(argv[e++]));
		while (argv[e])
			ft_lstadd_back(&a, ft_lstnew(ft_atoi(argv[e++])));
	}
	set_index(&a, ft_lstsize(a));
	if (has_duplicates(&a))
	{
		ft_printf("Error\n");
		return (0);
	}
	if (is_in_order(&a) || ft_lstsize(a) < 2)
		return (0);
	man_rad_chun(&a, ft_lstsize(a));
	ft_lstclear(&a);
	return (0);
}
