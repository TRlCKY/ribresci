/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 17:09:58 by ribresci          #+#    #+#             */
/*   Updated: 2026/10/14 17:10:16 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

t_heap	create_heap(int n, char *scheduler, int burnout)
{
	t_heap	heap;

	memset(&heap, 0, sizeof(heap));
	if (pthread_mutex_init(&heap.mutex, NULL) != 0)
		return (heap.error = 1, heap);
	heap.size = 0;
	heap.capacity = n;
	heap.burnout = burnout;
	heap.coders = malloc(sizeof(t_coder) * n);
	if (!heap.coders)
		return (heap.error = 1, heap);
	heap.scheduler = malloc(sizeof(char) * (strlen(scheduler) + 1));
	if (!heap.scheduler)
		return (heap.error = 1, heap);
	ft_strlcpy(heap.scheduler, scheduler, strlen(scheduler) + 1);
	return (heap.error = 0, heap);
}
