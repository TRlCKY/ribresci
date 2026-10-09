/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 16:45:49 by ribresci          #+#    #+#             */
/*   Updated: 2026/10/09 17:31:00 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

unsigned int	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	e;

	i = 0;
	e = 0;
	if (src && dest)
	{
		while (src[e])
			e++;
		if (size > 0)
		{
			while (src[i] != '\0' && i < size - 1)
			{
				dest[i] = src[i];
				i++;
			}
			dest[i] = '\0';
		}
	}
	return (e);
}

/*
void	freemonitor(t_monitor *monitor)
{
	if (monitor->sim->coders)
		free(monitor->sim->coders);
	if (monitor->sim->dongles)
		free(monitor->sim->dongles);
	if (monitor->sim->scheduler)
		free(monitor->sim->scheduler);
}
*/

void	freesim(t_sim *sim)
{
	int	i;

	i = 0;
	if (sim->dongles)
	{
		while (i < sim->num)
		{
			freeheap(&sim->dongles[i].heap);
			pthread_mutex_destroy(&sim->dongles[i].mutex);
			pthread_cond_destroy(&sim->dongles[i].cond);
			i++;
		}
		free(sim->dongles);
	}
	i = 0;
	if (sim->coders)
	{
		while (i < sim->num)
		{
			pthread_mutex_destroy(&sim->coders[i].mutex);
			i++;
		}
		free(sim->coders);
	}
	free(sim->scheduler);
}

void	freeheap(t_heap *heap)
{
	pthread_mutex_destroy(&heap->mutex);
	if (heap->coders)
		free(heap->coders);
	if (heap->scheduler)
		free(heap->scheduler);
}
