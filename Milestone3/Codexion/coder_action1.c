/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_action1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 12:41:48 by ribresci          #+#    #+#             */
/*   Updated: 2026/10/15 11:13:45 by ribresci         ###   ########.fr       */
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
	print_msg(coder, "is compiling\n");
	usleep(coder->compile * 1000);
	coder->n_compile--;
	return (0);
}

int	start_debugging(t_coder *coder)
{
	print_msg(coder, "is debugging\n");
	usleep(coder->debug * 1000);
	return (0);
}

int	start_refactoring(t_coder *coder)
{
	print_msg(coder, "is refactoring\n");
	usleep(coder->refactor * 1000);
	return (0);
}
