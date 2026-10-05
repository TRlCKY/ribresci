/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fifo_edf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 12:20:26 by ribresci          #+#    #+#             */
/*   Updated: 2026/10/05 16:40:06 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../H_Files/codexion.h"

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
	t_coder	*coder;

	coder = (t_coder *)arg;
	while (coder->n_compile != 0)
	{
		if (take_dongle_dx(coder) == 1)
			return (pthread_mutex_unlock(&coder->dx->mutex), NULL);
		if (take_dongle_sx(coder) == 1)
			return (pthread_mutex_unlock(&coder->dx->mutex), NULL);
		if (start_compiling(coder) == 1)
			return (pthread_mutex_unlock(&coder->dx->mutex), NULL);
		if (release_dongle_dx(coder) == 1)
			return (pthread_mutex_unlock(&coder->dx->mutex), NULL);
		if (release_dongle_sx(coder) == 1)
			return (pthread_mutex_unlock(&coder->dx->mutex), NULL);
		if (start_debugging(coder) == 1)
			return (pthread_mutex_unlock(&coder->dx->mutex), NULL);
		if (start_refactoring(coder) == 1)
			return (pthread_mutex_unlock(&coder->dx->mutex), NULL);
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
	t_monitor	*mntr;
	int			i;
	int			finish;

	mntr = (t_monitor *)arg;
	finish = 1;
	while (finish)
	{
		i = -1;
		while (++i < mntr->sim.num)
		{
			if (mntr->sim.coders[i].n_compile != 0
				&& (mntr->sim.coders[i].burnout
					> current_time(mntr->sim.start)))
			{
				write_error(mntr->sim.coders[i].id,
					current_time(mntr->sim.start));
				finish = 0;
			}
			else
				finish = check_coders(mntr);
		}
		usleep(1000);
	}
	return (free_monitor(mntr), NULL);
}

int	*check_coders(t_monitor *mntr)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (i < mntr->sim.num)
	{
		if (mntr->sim.coders[i].n_compile == 0)
			x++;
		i++;
	}
	if (x == 0)
		return (freemonitor(*mntr), 0);
	return (1);
}
