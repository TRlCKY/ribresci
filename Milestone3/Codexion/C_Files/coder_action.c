/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 17:12:37 by ribresci          #+#    #+#             */
/*   Updated: 2026/10/05 16:33:57 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../H_Files/codexion.h"

int	take_dongle_dx(t_coder *cdr)
{
	if (cdr->n_compile == 0)
		return (0);
	if (pthread_mutex_lock(&cdr->dx->mutex) != 0)
	{
		cdr->error = 1;
		return (1);
	}
	while (cdr->dx->used == 1)
		pthread_cond_wait(&cdr->dx->cond, &cdr->dx->mutex);
	if (cdr->dx->used == 0)
	{
		printf("%d %d has taken a dongle\n", current_time(cdr->start), cdr->id);
		cdr->dx->used = 1;
	}
	if (pthread_mutex_unlock(&cdr->dx->mutex))
	{
		cdr->error = 1;
		return (1);
	}
	return (0);
}

int	take_dongle_sx(t_coder *cdr)
{
	if (pthread_mutex_lock(&cdr->sx->mutex) != 0)
	{
		cdr->error = 1;
		return (1);
	}
	while (cdr->sx->used == 1)
		pthread_cond_wait(&cdr->sx->cond, &cdr->sx->mutex);
	if (cdr->sx->used == 0)
	{
		printf("%d %d has taken a dongle\n", current_time(cdr->start), cdr->id);
		cdr->sx->used = 1;
	}
	if (pthread_mutex_unlock(&cdr->sx->mutex) != 0)
	{
		cdr->error = 1;
		return (1);
	}
	return (0);
}

int	start_compiling(t_coder *coder)
{
	coder->last_compile_start = current_time(coder->start);
	printf("%d %d is compiling\n", current_time(coder->start), coder->id);
	usleep(coder->compile * 1000);
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
