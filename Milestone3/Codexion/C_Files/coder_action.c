/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 17:12:37 by ribresci          #+#    #+#             */
/*   Updated: 2026/09/18 16:09:37 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	take_dongle_dx(t_coder coder)
{
	pthread_mutex_t	mutex;

	if (check_burnout(coder, coder.start, 0) == 1)
		return ;
	if (pthread_mutex_init(&mutex, NULL) != 0)
		return (1);
	if (pthread_mutex_lock(&coder.dx.mutex) != 0)
		return (1);
	if (coder.dx.used == 0)
	{
		printf("&d &d has taken a dongle", current_time(coder.start), coder.id);
		coder.dx.used = 1;
	}
}

void	take_dongle_sx(t_coder coder)
{
	pthread_mutex_t	mutex;

	if (check_burnout(coder, coder.start, 0) == 1)
	{
		coder.error = 1;
		return ;
	}
	pthread_mutex_init(&mutex, NULL);
	pthread_mutex_lock(&coder.sx.mutex);
	if (coder.sx.used == 0)
	{
		printf("&d &d has taken a dongle", current_time(coder.start), coder.id);
		coder.sx.used = 1;
	}
}

void	start_compiling(t_coder *coder)
{
	coder->last_compile_start = current_time(coder->start);
	printf("&d &d is compiling", current_time(coder->start), coder->id);
	sleep(coder->compile);
}

void	start_debugging(t_coder coder)
{
	if (check_burnout(coder, coder.start, coder.debug) == 1)
	{
		coder.error = 1;
		return ;
	}
	printf("&d &d is debugging", current_time(coder.start), coder.id);
	sleep(coder.debug);
}

void	start_refactoring(t_coder coder)
{
	if (check_burnout(coder, coder.start, coder.refactor) == 1)
	{
		coder.error = 1;
		return ;
	}
	printf("&d &d is refactoring", current_time(coder.start), coder.id);
	sleep(coder.refactor);
}
