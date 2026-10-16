/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fifo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 12:20:26 by ribresci          #+#    #+#             */
/*   Updated: 2026/10/16 17:15:16 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

// Iniziano a programmare se rispettano le condizioni con scheduler="fifo"
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

// Quando c'e' solo un coder, prende l'unica dongle che ha e va in burnout,
// non avendone un altra
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

// Prende prima la chiavetta destra e poi la sinistra, se puo' farlo
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
	if (coder->sx->used == 0 && coder->dx->used == 0)
		if (coder->dx->cooldown_time - current_time(coder->start) <= 0
			&& coder->sx->cooldown_time - current_time(coder->start) <= 0)
			if (take_dongle_dx(coder) == 0)
				if (take_dongle_sx(coder) == 0)
					return (1);
	pthread_mutex_unlock(&coder->dx->mutex);
	pthread_mutex_unlock(&coder->sx->mutex);
	return (0);
}

// Prende prima la chiavetta sinistra e poi la destra, se puo' farlo
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
	if (coder->sx->used == 0 && coder->dx->used == 0)
		if (coder->dx->cooldown_time - current_time(coder->start) <= 0
			&& coder->sx->cooldown_time - current_time(coder->start) <= 0)
			if (take_dongle_sx(coder) == 0)
				if (take_dongle_dx(coder) == 0)
					return (1);
	pthread_mutex_unlock(&coder->sx->mutex);
	pthread_mutex_unlock(&coder->dx->mutex);
	return (0);
}

// A seconda dell'id delle chiavette si decide quale prendere prima (si prende
// quella con l'id piu' basso per evitare che tutti prendano ad esempio la 
// destra e nessuno la sinistra). con 3 coder si ha:
// *coder1, sx=0, dx = 1 (prende prima la sx)
// *coder2, sx=1, dx = 2 (prende prima la sx)
// *coder3, sx=2, dx = 0 (prende prima la dx)
int	can_take_both(t_coder *coder)
{
	if (coder->dx->id < coder->sx->id)
		return (take_dx_sx(coder));
	return (take_sx_dx(coder));
}
