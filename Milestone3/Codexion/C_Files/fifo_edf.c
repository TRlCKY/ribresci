/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fifo_edf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 12:20:26 by ribresci          #+#    #+#             */
/*   Updated: 2026/09/18 16:14:25 by ribresci         ###   ########.fr       */
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

int	fifo(t_sim sim)
{
	pthread_t	*thread;
	int			i;

	i = 0;
	return (0);
}

int	edf(t_sim sim)
{
	pthread_t	*thread;
	int			i;

	i = 0;
	return (0);
}

// Controlla che i coders non vadano in burnout
void	*check(void *arg)
{
	t_monitor	*mntr;
	t_coder		cdr;
	int			end;
	int			i;
	int			now;

	mntr = (t_monitor *)arg;
	while (!mntr->error)
	{
		i = 0;
		while (i < mntr->sim.num)
		{
			now = current_time(mntr->sim.start);
			cdr = mntr->sim.coders[i];
			if (now >= cdr.burnout + cdr.last_compile_start)
			{
				printf("%d %d burned out\n", now, cdr.id);
				mntr->error = 1;
				return (NULL);
			}
			i++;
		}
		
	}
	return (NULL);
}

int	start(t_sim sim, t_monitor *monitor, int scheduler)
{
	int	i;

	i = 0;
	if (pthread_create(&monitor->monitor_t, NULL, check, monitor) != 0)
		return (1);
	while (i < sim.num)
	{
		if (pthread_create(&sim.coders[i].thread, NULL, use_dongle,
				&sim.coders[i]) != 0)
			return (1);
		i++;
	}
	pthread_join(monitor->monitor_t, NULL);
	if (monitor->error == 1)
		return (1);
	i = 0;
	while (i < sim.num)
	{
		if (pthread_join(sim.coders[i].thread, NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}
