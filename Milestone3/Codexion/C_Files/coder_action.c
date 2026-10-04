/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 17:12:37 by ribresci          #+#    #+#             */
/*   Updated: 2026/10/02 18:00:35 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../H_Files/codexion.h"

int	take_dongle_dx(t_coder *cdr)
{
	if (cdr->n_compile == 0)
		return (0);
	if (check_burnout(*cdr, cdr->start, 0) == 1)
	{
		cdr->error = 1;
		return (1);
	}
	if (pthread_mutex_lock(&cdr->dx->mutex) != 0)
	{
		cdr->error = 1;
		return (1);
	}
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
	if (check_burnout(*cdr, cdr->start, 0) == 1)
	{
		cdr->error = 1;
		return (1);
	}
	if (pthread_mutex_lock(&cdr->sx->mutex) != 0)
	{
		cdr->error = 1;
		return (1);
	}
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
	if (check_burnout(*coder, coder->start, coder->compile))
	{
		coder->error = 1;
		return (1);
	}
	return (0);
}

int	start_debugging(t_coder *coder)
{
	printf("%d %d is debugging\n", current_time(coder->start), coder->id);
	usleep(coder->debug * 1000);
	if (check_burnout(*coder, coder->start, coder->debug) == 1)
	{
		coder->error = 1;
		return (1);
	}
	return (0);
}

int	start_refactoring(t_coder *coder)
{
	printf("%d %d is refactoring\n", current_time(coder->start), coder->id);
	usleep(coder->refactor * 1000);
	if (check_burnout(*coder, coder->start, coder->refactor) == 1)
	{
		coder->error = 1;
		return (1);
	}
	return (0);
}
