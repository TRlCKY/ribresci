/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 17:12:37 by ribresci          #+#    #+#             */
/*   Updated: 2026/10/06 15:05:53 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	take_dongle_dx(t_coder *cdr)
{
	t_coder	*next;

	if (cdr->n_compile == 0)
		return (0);
	if (pthread_mutex_lock(&cdr->dx->mutex) != 0)
		return (1);
	add_back(&cdr->dx->heap, cdr);
	while (1)
	{
		next = get_next(&cdr->dx->heap);
		if (next && next->id == cdr->id && cdr->dx->used == 0
			&& current_time(cdr->start) >= cdr->dx->cooldown_time)
			break;
		pthread_mutex_lock(&cdr->dx->mutex);
		pthread_cond_wait(&cdr->dx->cond, &cdr->dx->mutex);
		pthread_mutex_unlock(&cdr->dx->mutex);
	}
	pop_front(&cdr->dx->heap);
	printf("%d %d has taken a dongle\n", current_time(cdr->start), cdr->id);
	cdr->dx->used = 1;
	if (pthread_mutex_unlock(&cdr->dx->mutex))
		return (1);
	return (0);
}

int	take_dongle_sx(t_coder *cdr)
{
	t_coder	*next;

	if (cdr->n_compile == 0)
		return (0);
	if (pthread_mutex_lock(&cdr->sx->mutex) != 0)
		return (1);
	add_back(&cdr->sx->heap, cdr);
	while (1)
	{
		next = get_next(&cdr->sx->heap);
		if (next && next->id == cdr->id && cdr->sx->used == 0
			&& current_time(cdr->start) >= cdr->sx->cooldown_time)
			break;
		pthread_mutex_lock(&cdr->sx->mutex);
		pthread_cond_wait(&cdr->sx->cond, &cdr->sx->mutex);
		pthread_mutex_unlock(&cdr->sx->mutex);
	}
	pop_front(&cdr->sx->heap);
	printf("%d %d has taken a dongle\n", current_time(cdr->start), cdr->id);
	cdr->sx->used = 1;
	if (pthread_mutex_unlock(&cdr->sx->mutex))
		return (1);
	return (0);
}

int	start_compiling(t_coder *coder)
{
	coder->last_compile_start = current_time(coder->start);
	printf("%d %d is compiling\n", current_time(coder->start), coder->id);
	usleep(coder->compile * 1000);
	coder->n_compile--;
	return (0);
}

int	start_debugging(t_coder *coder)
{
	printf("%d %d is debugging\n", current_time(coder->start), coder->id);
	usleep(coder->debug * 1000);
	return (0);
}

int	start_refactoring(t_coder *coder)
{
	printf("%d %d is refactoring\n", current_time(coder->start), coder->id);
	usleep(coder->refactor * 1000);
	return (0);
}
