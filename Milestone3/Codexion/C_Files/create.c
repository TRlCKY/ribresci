/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 14:51:00 by ribresci          #+#    #+#             */
/*   Updated: 2026/09/02 17:10:51 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

t_dongle	*create_dongles(t_sim sim, t_dongle *dongles)
{
	t_dongle	dngl;
	int			i;

	i = 0;
	while (i != sim.num)
	{
		dngl.id = i + 1;
		dngl.cooldown = sim.cooldown;
		dngl.used = 0;
		dongles[i] = dngl;
		i++;
	}
}

t_coder	*create_coders(t_sim sim, t_coder *coders, t_dongle *dongles)
{
	t_coder	cdr;
	int		i;

	i = 0;
	while (i != sim.num)
	{
		cdr.id = i + 1;
		cdr.sx = dongles[i];
		if (i == sim.num - 1)
			cdr.dx = dongles[0];
		else
			cdr.dx = dongles[i + 1];
		coders[i] = cdr;
		i++;
	}
	return (coders);
}

t_sim	create_sim(t_sim sim, int *array, int len)
{
	clock_gettime(CLOCK_MONOTONIC, &sim.start);
	sim.num = array[0];
	sim.burnout = array[1];
	sim.compile = array[2];
	sim.debug = array[3];
	sim.refactor = array[4];
	sim.n_compile = array[5];
	sim.cooldown = array[6];
	strlcopy(sim.scheduler, array[7], len);
	sim.dongles = malloc(sizeof(t_dongle) * sim.num);
	if (!sim.dongles)
		return (sim.error = 1, free(sim.dongles), sim);
	sim.dongles = create_dongles(sim, sim.dongles);
	if (!sim.coders)
		return (sim.error = 1, free(sim.coders), sim);
	sim.coders = create_coders(sim, sim.coders, sim.dongles);
	return (sim);
}
