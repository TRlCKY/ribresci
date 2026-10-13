/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_action1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 12:41:48 by ribresci          #+#    #+#             */
/*   Updated: 2026/10/13 15:52:38 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	release_dongles(t_coder *coder, int x)
{
	if (coder->dx)
	{
		pthread_mutex_lock(&coder->dx->mutex);
		coder->dx->used = 0;
		if (x == 1)
			coder->dx->cooldown_time = current_time(coder->start)
				+ coder->dx->cooldown;
		pthread_cond_broadcast(&coder->dx->cond);
		pthread_mutex_unlock(&coder->dx->mutex);
	}
	if (coder->sx)
	{
		pthread_mutex_lock(&coder->sx->mutex);
		coder->sx->used = 0;
		if (x)
			coder->sx->cooldown_time = current_time(coder->start)
				+ coder->sx->cooldown;
		pthread_cond_broadcast(&coder->sx->cond);
		pthread_mutex_unlock(&coder->sx->mutex);
	}
	return (0);
}

int	start_compiling(t_coder *coder)
{
	coder->last_compile_start = current_time(coder->start);
	pthread_mutex_lock(coder->mutex);
	printf("%d %d is compiling\n", current_time(coder->start), coder->id);
	pthread_mutex_unlock(coder->mutex);
	usleep(coder->compile * 1000);
	coder->n_compile--;
	return (0);
}

int	start_debugging(t_coder *coder)
{
	pthread_mutex_lock(coder->mutex);
	printf("%d %d is debugging\n", current_time(coder->start), coder->id);
	pthread_mutex_unlock(coder->mutex);
	usleep(coder->debug * 1000);
	return (0);
}

int	start_refactoring(t_coder *coder)
{
	pthread_mutex_lock(coder->mutex);
	printf("%d %d is refactoring\n", current_time(coder->start), coder->id);
	pthread_mutex_unlock(coder->mutex);
	usleep(coder->refactor * 1000);
	return (0);
}
