/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fifo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 12:20:26 by ribresci          #+#    #+#             */
/*   Updated: 2026/10/20 12:37:55 by ribresci         ###   ########.fr       */
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
	if (coder->dx->used == 1)
		return (NULL);
	coder->dx->used = 1;
	print_msg(coder, "has taken a dongle\n");
	pthread_mutex_unlock(&coder->dx->mutex);
	while (coder->error == 0 && coder->n_compile != 0)
		usleep(1000);
	release_dongles(coder, 1);
	return (NULL);
}

// A seconda dell'id delle chiavette si decide quale prendere prima (si prende
// quella con l'id piu' basso per evitare che tutti prendano ad esempio la 
// destra e nessuno la sinistra). con 3 coder si ha:
// *coder1, sx=0, dx = 1 (prende prima la sx)
// *coder2, sx=1, dx = 2 (prende prima la sx)
// *coder3, sx=2, dx = 0 (prende prima la dx)
int	can_take_both(t_coder *c)
{
	t_dongle	*a;
	t_dongle	*b;

	a = c->dx;
	b = c->sx;
	if (c->dx->id > c->sx->id)
	{
		a = c->sx;
		b = c->dx;
	}
	pthread_mutex_lock(&a->mutex);
	pthread_mutex_lock(&b->mutex);
	add_back(&a->heap, c);
	add_back(&b->heap, c);
	if (c == get_next(&a->heap) && c == get_next(&b->heap)
		&& !a->used && !b->used && a->cooldown_time <= current_time(c->start)
		&& b->cooldown_time <= current_time(c->start))
		if (take_dongle(c, a) == 0)
			if (take_dongle(c, b) == 0)
				return (1);
	pthread_mutex_unlock(&a->mutex);
	pthread_mutex_unlock(&b->mutex);
	return (0);
}
