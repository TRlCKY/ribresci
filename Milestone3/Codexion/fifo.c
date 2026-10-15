/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fifo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 12:20:26 by ribresci          #+#    #+#             */
/*   Updated: 2026/10/15 12:45:39 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

/*
* (1) Number of coders and dongles
*
* (2) Time to burnout(If a coder did not start compiling within
* 	  time_to_burnout milliseconds since the beginning of their last compile
*  	  or the beginning of the simulation, they burn out.)
*
* (3) Time to compile(During that time, they must hold two dongles)
*
* (4) Time to debug(The time a coder will spend debugging)
*
* (5) Time to refactor(After completing the refactoring phase, the coder will 
* 	  attempt to acquire dongles and start compiling again.)
*
* (6) Number of compiles required(If all coders have compiled at least this
* 	  many times, the simulation stops. Otherwise, it stops when a coder burns
* 	  out)
*
* (7) Dongle cooldown(After being released, a dongle is unavailable until its
* 	  cooldown has passed)
*
* (8) Scheduler(first_in_first_out/earliest_deadline_first=
* 	  last_compile_start + time_to_burnout)
*/

// Dopo il controllo del burnout vengono effettuate le varie azioni
void	*use_dongle_fifo(void *arg)
{
	t_coder		*coder;

	coder = (t_coder *)arg;
	if (coder->sx == NULL)
		return (one_coder(coder));
	while (coder->n_compile != 0 && coder->error != 1)
	{
		if (can_take_both(coder) == 1)
		{
			if (coder->error == 1 || start_compiling(coder) == 1)
				return (NULL);
			if (coder->error == 1 || release_dongles(coder, 1) == 1)
				return (NULL);
			if (coder->error == 1 || start_debugging(coder) == 1)
				return (NULL);
			if (coder->error == 1 || start_refactoring(coder) == 1)
				return (NULL);
		}
		usleep(1000);
	}
	return (NULL);
}

void	*one_coder(void *arg)
{
	t_coder	*coder;

	coder = (t_coder *)arg;
	pthread_mutex_lock(&coder->dx->mutex);
	if (take_dongle_dx(coder) == 1)
		return (NULL);
	while (coder->error == 0 && coder->n_compile != 0)
		usleep(1000);
	release_dongles(coder, 1);
	return (NULL);
}

int	take_dx_sx(t_coder *coder)
{
	pthread_mutex_lock(&coder->dx->mutex);
	pthread_mutex_lock(&coder->sx->mutex);
	if (coder->dx->used == 1 || coder->sx->used == 1)
	{
		pthread_mutex_unlock(&coder->sx->mutex);
		pthread_mutex_unlock(&coder->dx->mutex);
		return (0);
	}
	if (take_dongle_dx(coder) == 1)
		return (pthread_mutex_unlock(&coder->sx->mutex), 0);
	if (take_dongle_sx(coder) == 1)
		return (release_dongles(coder, 0), 0);
	return (1);
}

int	take_sx_dx(t_coder *coder)
{
	pthread_mutex_lock(&coder->sx->mutex);
	pthread_mutex_lock(&coder->dx->mutex);
	if (coder->sx->used == 1 || coder->dx->used == 1)
	{
		pthread_mutex_unlock(&coder->dx->mutex);
		pthread_mutex_unlock(&coder->sx->mutex);
		return (0);
	}
	if (take_dongle_sx(coder) == 1)
		return (pthread_mutex_unlock(&coder->dx->mutex), 0);
	if (take_dongle_dx(coder) == 1)
		return (release_dongles(coder, 0), 0);
	return (1);
}

int	can_take_both(t_coder *coder)
{
	if (coder->dx->id < coder->sx->id)
		return (take_dx_sx(coder));
	return (take_sx_dx(coder));
}

// Come funziona un EDF corretto
// 1) Registrarsi in entrambe le heap (dx e sx) appena si vuole compilare, non 
//    quando le dongle sono già libere.
// 2) Prendere le dongle solo se:
//    * si è in testa a entrambe le heap;
//    * entrambe le dongle sono libere (used == 0);
//    * il cooldown di entrambe è passato.
// 3) Fare il controllo e la presa nella stessa sezione critica, tenendo i 
//    mutex delle due dongle in ordine di id.
// 4) Dopo la presa, pop_front da entrambe le heap.

// Questo schema non va in deadlock. Il coder con la deadline più vicina tra 
// quelli in attesa è in testa a entrambe le sue heap, perché chiunque 
// condivida una dongle con lui ha una deadline più tarda. Quindi non può 
// mai essere bloccato dalla posizione in coda, ma solo da used o dal cooldown,
// che finiscono da soli. La deadline resta fissa mentre aspetta 
// (last_compile_start cambia solo quando compila, cioè quando è già uscito 
// dalla heap), quindi non c’è starvation. Il tie-break sull’id che hai 
// già in do_switch rende l’ordine totale.
