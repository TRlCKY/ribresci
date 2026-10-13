/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 16:45:49 by ribresci          #+#    #+#             */
/*   Updated: 2026/10/13 16:26:19 by ribresci         ###   ########.fr       */
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

char	**get_argv(t_sim *sim, char **argv)
{
	char	**argv0;

	argv0 = malloc(sizeof(char *) * 5);
	if (!argv0)
		return (sim->error = 1, argv0);
	argv0[0] = argv[3];
	argv0[1] = argv[4];
	argv0[2] = argv[5];
	argv0[3] = argv[6];
	argv0[4] = "\0";
	return (argv0);
}
