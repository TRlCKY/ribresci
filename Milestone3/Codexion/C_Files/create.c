/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 14:51:00 by ribresci          #+#    #+#             */
/*   Updated: 2026/09/18 16:09:59 by ribresci         ###   ########.fr       */
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
		if (pthread_mutex_init(&dngl.mutex, NULL) != 0)
			return (NULL);
		dngl.cooldown = sim.cooldown;
		if (pthread_cond_init(&dngl.cond, NULL) != 0)
			return (NULL);
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
		cdr.start = sim.start;
		cdr.id = i + 1;
		cdr.burnout = sim.burnout;
		cdr.compile = sim.compile;
		cdr.debug = sim.debug;
		cdr.refactor = sim.refactor;
		cdr.n_compile = sim.n_compile;
		cdr.error = 0;
		cdr.last_compile_start = current_time(sim.start);
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
	sim.scheduler = malloc(sizeof(char) * (strlen(argv[8]) + 1));
	if (!sim.scheduler)
		return (sim.error = 1, freeall(sim), sim);
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

t_monitor	create_monitor(t_monitor monitor, t_sim sim)
{
	monitor.error = 0;
	monitor.sim = sim;
	return (monitor);
}
