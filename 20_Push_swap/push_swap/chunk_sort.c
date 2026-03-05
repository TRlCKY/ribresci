/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   chunk_sort.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: ribresci <ribresci@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2026/02/20 17:06:42 by ribresci		  #+#	#+#			 */
/*   Updated: 2026/03/05 18:50:20 by ribresci		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "push_swap.h"

// Se il valore piu' alto non si trova in prima/ultima posizione lo trova e lo 
// mette o in prima o in ultima posizione
int	find_max(t_list **b)
{
	int		max;
	int		x;
	int		i;
	t_list	*c;

	if (!b || !*b)
		return (-1);
	c = *b;
	max = c->index;
	x = 0;
	i = 0;
	while (c)
	{
		if (c->index > max)
		{
			max = c->index;
			x = i;
		}
		c = c->next;
		i++;
	}
	return (x);
}

// Ripusha tutto in a mandando prima il piu grande, sistemando le posizioni se
// non si trova in cima o in fondo alla lista
void	send_back(t_list **a, t_list **b)
{
	int		i;

	while (*b)
	{
		i = find_max(*b);
		while (i != 0 || i != ft_lstsize(*b))
		{
			if (i > ft_lstsize(*b) / 2)
			{
				reverse_rotate(b, NULL, 1);
				i++;
			}
			else
			{
				rotate(b, NULL, 1);
				i--;
			}
		}
		push(a, b, 0);
	}
}

// Trova il massimo con x = 0 e il minimo con x = 1
// Si mette size - 20 per poter prendere solo il massimo e il minimo di ogni
// chunk.
int	get_max_min(t_list **a, int x, int n)
{
	t_list	*c;
	int		i;

	c = *a;
	i = c->index;
	while (c)
	{
		if (i < c->index && x == 0)
			i = c->index;
		if (i > c->index && x == 1 && c->index < n)
			i = c->index;
		c = c->next;
	}
	return (i);
}

// Trova il primo elemento appartenente al chunk tra max e min e decide se 
// usare ra o rra per portare quell'elemento in cima alla lista.
// Nel primo while scorre la lista tra i valori max e min resituiti da
// get_max_min per trovare gli elementi da pushare in B
void	find_chunk(t_list **a, int size, int chunk_size, int n)
{
	int		max;
	int		min;
	int		i;
	t_list	*c;

	c = *a;
	i = 0;
	max = get_max_min(a, 0, size - (n * chunk_size));
	min = get_max_min(a, 1, size - (n * chunk_size));
	while (c->index > max || c->index < min)
	{
		i++;
		c = c->next;
	}
	while ((*a)->index != c->index)
	{
		if (i >= chunk_size - (n * chunk_size) / 2)
			reverse_rotate(a, NULL, 0);
		else
			rotate(a, NULL, 0);
	}
}

// n e' il numero di chunk su cui lavorare finche' non si esauriscono tutti 
// gli elementi del chunk. chunk_size e' il numero di elementi per chunk e il
// resto  della divisione viene aggiunto al primo chunk. Poi si pusha 
// l'elemento in B. Se l'elemento e' nella parte dei numeri piu' piccoli viene
// messo in fondo a B. Si inizia dagli elementi piu' piccoli e poi a salire
void	chunk_sort(t_list **a, int size)
{
	int		n;
	int		i;
	int		chunk_size;
	int		chunk_size2;
	t_list	*b;

	b = NULL;
	n = 5;
	while (n--)
	{
		chunk_size = size / 5;
		if (n == 0)
			chunk_size += size % 5;
		chunk_size2 = chunk_size;
		while (chunk_size--)
		{
			find_chunk(a, size, chunk_size2, n);
			push(&b, a, 1);
		}
		if (b->index < size - (n * chunk_size) - (chunk_size2 / 2))
			rotate(&b, NULL, 1);
	}
	send_back(a, &b);
}
