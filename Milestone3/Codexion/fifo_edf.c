/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fifo_edf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 12:20:26 by ribresci          #+#    #+#             */
/*   Updated: 2026/10/09 17:01:29 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

/*
* (0) Number of coders and dongles
*
* (1) Time to burnout(If a coder did not start compiling within
* 	  time_to_burnout milliseconds since the beginning of their last compile
*  	  or the beginning of the simulation, they burn out.)
*
* (2) Time to compile(During that time, they must hold two dongles)
*
* (3) Time to debug(The time a coder will spend debugging)
*
* (4) Time to refactor(After completing the refactoring phase, the coder will 
* 	  attempt to acquire dongles and start compiling again.)
*
* (5) Number of compiles required(If all coders have compiled at least this
* 	  many times, the simulation stops. Otherwise, it stops when a coder burns
* 	  out)
*
* (6) Dongle cooldown(After being released, a dongle is unavailable until its
* 	  cooldown has passed)
*
* (7) Scheduler(first_in_first_out/earliest_deadline_first=
* 	  last_compile_start + time_to_burnout)
*/

// Dopo il controllo del burnout vengono effettuate le varie azioni
void	*use_dongle_fifo(void *arg)
{
	t_coder		*coder;

	coder = (t_coder *)arg;
	while (coder->n_compile != 0 && coder->error != 1)
	{
		pthread_mutex_lock(&coder->mutex);
		if (coder->dx->used == 1 || coder->sx->used == 1)
			usleep(1000);
		pthread_mutex_unlock(&coder->mutex);
		if (take_dongle_dx(coder) == 1)
			return (pthread_mutex_unlock(&coder->dx->mutex), NULL);
		if (take_dongle_sx(coder) == 1)
			return (pthread_mutex_unlock(&coder->sx->mutex), NULL);
		if (start_compiling(coder) == 1)
			return (NULL);
		if (release_dongle_dx(coder) == 1)
			return (NULL);
		if (release_dongle_sx(coder) == 1)
			return (NULL);
		if (start_debugging(coder) == 1)
			return (NULL);
		if (start_refactoring(coder) == 1)
			return (NULL);
		printf("ciaooooo\n");
	}
	return (NULL);
}

// Dopo il controllo del burnout vengono effettuate le varie azioni
void	*use_dongle_edf(void *arg)
{
	t_coder	*coder;

	coder = (t_coder *)arg;
	return (NULL);
}

// Controlla che i coders non vadano in burnout o abbiano finito
void	*check(void *arg)
{
	t_monitor	*m;
	int			i;

	m = (t_monitor *)arg;
	while (m->finish)
	{
		i = -1;
		while (++i < m->sim->num)
		{
			if (m->sim->coders[i].n_compile != 0 && check_time(m, i))
			{
				print_er(current_time(m->sim->start), m->sim->coders[i].id);
				m->finish = 0;
				printf("Coder error: %d\n", m->sim->coders[i].error);
				m->sim->coders[i].error = 1;
				i = m->sim->num;
			}
			if (check_coders(m) == 0)
			{
				m->finish = 0;
				i = m->sim->num;
			}
		}
		usleep(1000);
	}
	return (NULL);
}

int	check_coders(t_monitor *mntr)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (i < mntr->sim->num)
	{
		if (mntr->sim->coders[i].n_compile == 0)
			x++;
		i++;
	}
	if (x == mntr->sim->num)
		return (0);
	return (1);
}

int	check_time(t_monitor *mntr, int i)
{
	if (current_time(mntr->sim->start)
		- mntr->sim->coders[i].last_compile_start
		>= mntr->sim->coders[i].burnout)
		return (1);
	return (0);
}
