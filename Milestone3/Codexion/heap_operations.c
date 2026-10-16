/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 14:00:29 by ribresci          #+#    #+#             */
/*   Updated: 2026/10/16 17:05:44 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

// Aggiunge in fondo alla coda un coder
void	add_back(t_heap *heap, t_coder *coder)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&heap->mutex);
	if (is_inside(heap, *coder) || heap->size >= heap->capacity)
	{
		pthread_mutex_unlock(&heap->mutex);
		return ;
	}
	heap->coders[heap->size] = coder;
	heap->size++;
	if (strcmp(heap->scheduler, "edf") == 0)
		sort_heap(heap);
	pthread_mutex_unlock(&heap->mutex);
}

// Rimuove il primo coder della coda quando ha finito di compilare
void	pop_front(t_heap *heap)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&heap->mutex);
	if (heap->size > 0)
	{
		while (i < heap->size - 1)
		{
			heap->coders[i] = heap->coders[i + 1];
			i++;
		}
		heap->size--;
	}
	pthread_mutex_unlock(&heap->mutex);
}

// In caso di scheduler=="edf" si ordina la coda per la deadline più vicina
void	sort_heap(t_heap *heap)
{
	int		i;
	int		e;
	t_coder	*coder0;

	e = 0;
	while (e < heap->size)
	{
		i = 0;
		while (i < heap->size - 1)
		{
			if (do_switch(heap->coders[i], heap->coders[i + 1], heap->burnout))
			{
				coder0 = heap->coders[i];
				heap->coders[i] = heap->coders[i + 1];
				heap->coders[i + 1] = coder0;
			}
			i++;
		}
		e++;
	}
}

// Controlla se vanno scambiati gli elementi
int	do_switch(t_coder *c1, t_coder *c2, int burnout)
{
	long	d1;
	long	d2;

	d1 = c1->last_compile_start + burnout;
	d2 = c2->last_compile_start + burnout;
	if (d1 > d2)
		return (1);
	return (0);
}

// Controlla se il coder e' gia' all'interno dell'heap
int	is_inside(t_heap *heap, t_coder coder)
{
	int	i;

	i = 0;
	while (i < heap->size)
	{
		if (heap->coders[i]->id == coder.id)
			return (1);
		i++;
	}
	return (0);
}
