/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 16:45:49 by ribresci          #+#    #+#             */
/*   Updated: 2026/09/28 18:13:19 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../H_Files/codexion.h"

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

void	freemonitor(t_monitor monitor)
{
	if (monitor.sim.coders)
		free(monitor.sim.coders);
	if (monitor.sim.dongles)
		free(monitor.sim.dongles);
	freesim(monitor.sim);
	freeheap(monitor.heap);
	free(&monitor);
}

void	freesim(t_sim sim)
{
	if (sim.coders)
		free(sim.coders);
	if (sim.dongles)
		free(sim.dongles);
	free(&sim);
}

void	freeheap(t_heap heap)
{
	if (heap.coders)
		free(heap.coders);
	free(&heap);
}
