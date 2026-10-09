/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 14:00:29 by ribresci          #+#    #+#             */
/*   Updated: 2026/10/09 16:55:41 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

// Aggiunge in coda un coder
void	add_back(t_heap *heap, t_coder *coder)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&heap->mutex);
	if (is_inside(heap, *coder))
	{
		pthread_mutex_unlock(&heap->mutex);
		return ;
	}
	if (heap->size >= heap->capacity)
	{
		pthread_mutex_unlock(&heap->mutex);
		return ;
	}
	heap->coders[heap->size] = *coder;
	heap->size++;
	if (strcmp(heap->scheduler, "edf") == 0)
		sort_heap(heap);
	while (i < heap->size)
	{
		heap->coders[i].order = i;
		i++;
	}
	pthread_mutex_unlock(&heap->mutex);
}

// Rimuove il primo coder della coda quando ha finito di compilare
void	pop_front(t_heap *heap)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&heap->mutex);
	if (heap->size == 0)
	{
		pthread_mutex_unlock(&heap->mutex);
		return ;
	}
	while (i < heap->size - 1)
	{
		heap->coders[i] = heap->coders[i + 1];
		i++;
	}
	heap->size--;
	pthread_mutex_unlock(&heap->mutex);
}

// In caso di scheduler=="edf" si ordina la coda per la deadline più vicina
void	sort_heap(t_heap *heap)
{
	int		i;
	int		e;
	t_coder	coder0;

	e = 0;
	while (e < heap->size)
	{
		i = 0;
		while (i < heap->size - 1)
		{
			if (heap->coders[i].last_compile_start + heap->coders[i].burnout
				> heap->coders[i + 1].last_compile_start
				+ heap->coders[i + 1].burnout)
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

// Restuìituisce il primo coder senza rimuoverlo, con size==0 restituisce NULL
t_coder	*get_next(t_heap *heap)
{
	pthread_mutex_lock(&heap->mutex);
	if (heap->size == 0)
	{
		pthread_mutex_unlock(&heap->mutex);
		return (NULL);
	}
	else
	{
		pthread_mutex_unlock(&heap->mutex);
		return (&heap->coders[0]);
	}
	pthread_mutex_unlock(&heap->mutex);
}

int	is_inside(t_heap *heap, t_coder coder)
{
	int	i;

	i = 0;
	while (i < heap->size)
	{
		if (heap->coders[i].id == coder.id)
			return (1);
		i++;
	}
	return (0);
}
