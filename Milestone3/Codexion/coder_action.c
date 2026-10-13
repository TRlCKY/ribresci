/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 17:12:37 by ribresci          #+#    #+#             */
/*   Updated: 2026/10/13 16:13:22 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	take_dongle_dx(t_coder *cdr)
{
	t_coder			*next;
	long			time;
	struct timespec	deadline;

	if (cdr->n_compile == 0)
		return (0);
	add_back(&cdr->dx->heap, cdr);
	while (1 && cdr->error == 0)
	{
		next = get_next(&cdr->dx->heap);
		if (next && next->id == cdr->id && cdr->dx->used == 0)
		{
			time = cdr->dx->cooldown_time - current_time(cdr->start);
			if (time <= 0)
				break ;
			deadline = calculate_time(deadline, time);
			pthread_cond_timedwait(&cdr->dx->cond, &cdr->dx->mutex,
				&deadline);
		}
		else
			pthread_cond_wait(&cdr->dx->cond, &cdr->dx->mutex);
	}
	return (take_dongle_dx1(cdr));
}

int	take_dongle_dx1(t_coder *cdr)
{
	if (cdr->error == 1)
		return (pthread_mutex_unlock(&cdr->dx->mutex), 1);
	pop_front(&cdr->dx->heap);
	pthread_mutex_lock(cdr->mutex);
	printf("%d %d has taken a dongle\n", current_time(cdr->start), cdr->id);
	pthread_mutex_unlock(cdr->mutex);
	cdr->dx->used = 1;
	if (pthread_mutex_unlock(&cdr->dx->mutex) != 0)
		return (pthread_mutex_unlock(&cdr->dx->mutex), 1);
	return (0);
}

int	take_dongle_sx(t_coder *cdr)
{
	t_coder			*next;
	long			time;
	struct timespec	deadline;

	if (cdr->n_compile == 0)
		return (0);
	add_back(&cdr->sx->heap, cdr);
	while (1 && cdr->error == 0)
	{
		next = get_next(&cdr->sx->heap);
		if (next && next->id == cdr->id && cdr->sx->used == 0)
		{
			time = cdr->sx->cooldown_time - current_time(cdr->start);
			if (time <= 0)
				break ;
			deadline = calculate_time(deadline, time);
			pthread_cond_timedwait(&cdr->sx->cond, &cdr->sx->mutex,
				&deadline);
		}
		else
			pthread_cond_wait(&cdr->sx->cond, &cdr->sx->mutex);
	}
	return (take_dongle_sx1(cdr));
}

int	take_dongle_sx1(t_coder *cdr)
{
	if (cdr->error == 1)
	{
		pthread_mutex_unlock(&cdr->sx->mutex);
		return (1);
	}
	pop_front(&cdr->sx->heap);
	pthread_mutex_lock(cdr->mutex);
	printf("%d %d has taken a dongle\n", current_time(cdr->start), cdr->id);
	pthread_mutex_unlock(cdr->mutex);
	cdr->sx->used = 1;
	if (pthread_mutex_unlock(&cdr->sx->mutex) != 0)
		return (pthread_mutex_unlock(&cdr->sx->mutex), 1);
	return (0);
}

struct timespec	calculate_time(struct timespec deadline, long time)
{
	clock_gettime(CLOCK_REALTIME, &deadline);
	deadline.tv_sec += time / 1000;
	deadline.tv_nsec += (time % 1000) * 1000000L;
	if (deadline.tv_nsec >= 1000000000L)
	{
		deadline.tv_sec++;
		deadline.tv_nsec -= 1000000000L;
	}
	return (deadline);
}
