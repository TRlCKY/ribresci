/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 14:51:00 by ribresci          #+#    #+#             */
/*   Updated: 2026/09/04 14:19:59 by ribresci         ###   ########.fr       */
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
	t_coder			cdr;
	int				i;

	i = 0;
	while (i != sim.num)
	{
		coders[i].time = sim.start;
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

t_sim	create_sim(t_sim sim, char *argv)
{
	clock_gettime(CLOCK_MONOTONIC, &sim.start);
	sim.num = atoi(argv[1]);
	sim.burnout = atoi(argv[2]);
	sim.compile = atoi(argv[3]);
	sim.debug = atoi(argv[4]);
	sim.refactor = atoi(argv[5]);
	sim.n_compile = atoi(argv[6]);
	sim.cooldown = atoi(argv[7]);
	strlcopy(sim.scheduler, argv[8], strlen(argv[8]));
	sim.dongles = malloc(sizeof(t_dongle) * sim.num);
	if (!sim.dongles)
		return (sim.error = 1, freeall(sim), sim);
	sim.dongles = create_dongles(sim, sim.dongles);
	sim.coders = malloc(sizeof(t_coder) * sim.num);
	if (!sim.coders)
		return (sim.error = 1, freeall(sim), sim);
	sim.coders = create_coders(sim, sim.coders, sim.dongles);
	return (sim);
}

t_monitor	create_monitor(t_monitor monitor, t_sim sim, t_coder *coders,
	t_dongle *dongels)
{
	
	return (monitor);
}
