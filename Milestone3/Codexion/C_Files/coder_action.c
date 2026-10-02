/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 17:12:37 by ribresci          #+#    #+#             */
/*   Updated: 2026/10/02 12:52:51 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../H_Files/codexion.h"

int	take_dongle_dx(t_coder coder)
{
	pthread_mutex_t	mutex;

	if (coder.n_compile == 0)
		return (0);
	if (check_burnout(coder, coder.start, 0) == 1)
	{
		coder.error = 1;
		return (1);
	}
	if (pthread_mutex_init(&mutex, NULL) != 0)
	{
		coder.error = 1;
		return (1);
	}
	if (pthread_mutex_lock(&coder.dx.mutex) != 0)
	{
		coder.error = 1;
		return (1);
	}
	if (coder.dx.used == 0)
	{
		printf("%d %d has taken a dongle", current_time(coder.start), coder.id);
		coder.dx.used = 1;
	}
	return (0);
}

int	take_dongle_sx(t_coder coder)
{
	pthread_mutex_t	mutex;

	if (check_burnout(coder, coder.start, 0) == 1)
	{
		coder.error = 1;
		return (1);
	}
	if (pthread_mutex_init(&mutex, NULL) != 0)
	{
		coder.error = 1;
		return (1);
	}
	if (pthread_mutex_lock(&coder.sx.mutex) != 0)
	{
		coder.error = 1;
		return (1);
	}
	if (coder.sx.used == 0)
	{
		printf("%d %d has taken a dongle", current_time(coder.start), coder.id);
		coder.sx.used = 1;
	}
	return (0);
}

int	start_compiling(t_coder *coder)
{
	coder->last_compile_start = current_time(coder->start);
	printf("%d %d is compiling", current_time(coder->start), coder->id);
	sleep(coder->compile);
	if (check_burnout(*coder, coder->start, coder->compile))
	{
		coder->error = 1;
		return (1);
	}
	return (0);
}

int	start_debugging(t_coder coder)
{
	printf("%d %d is debugging", current_time(coder.start), coder.id);
	sleep(coder.debug);
	if (check_burnout(coder, coder.start, coder.debug) == 1)
	{
		coder.error = 1;
		return (1);
	}
	return (0);
}

int	start_refactoring(t_coder coder)
{
	printf("%d %d is refactoring", current_time(coder.start), coder.id);
	sleep(coder.refactor);
	if (check_burnout(coder, coder.start, coder.refactor) == 1)
	{
		coder.error = 1;
		return (1);
	}
	return (0);
}
