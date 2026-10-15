/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_operations1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 17:18:57 by ribresci          #+#    #+#             */
/*   Updated: 2026/10/15 18:05:36 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

// Restuituisce il primo coder senza rimuoverlo, con size==0 restituisce NULL
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
		return (heap->coders[0]);
	}
	pthread_mutex_unlock(&heap->mutex);
}
