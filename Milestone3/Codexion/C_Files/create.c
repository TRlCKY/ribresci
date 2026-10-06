/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 14:51:00 by ribresci          #+#    #+#             */
/*   Updated: 2026/10/06 12:18:42 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../H_Files/codexion.h"

t_dongle	*create_dongles(t_sim sim, t_dongle *dongles)
{
	int			i;

	i = 0;
	while (i != sim.num)
	{
		dongles[i].id = i + 1;
		dongles[i].cooldown = sim.cooldown;
		dongles[i].used = 0;
		if (pthread_mutex_init(&dongles[i].mutex, NULL) != 0)
			return (NULL);
		if (pthread_cond_init(&dongles[i].cond, NULL) != 0)
			return (NULL);
		dongles[i].heap = create_heap(sim.num, sim.scheduler);
		i++;
	}
	return (dongles);
}

t_coder	*create_coders(t_sim sim, t_coder *coders, t_dongle *dongles)
{
	t_coder	cdr;
	int		i;

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
		cdr.order = 0;
		cdr.last_compile_start = current_time(sim.start);
		cdr.sx = &dongles[i];
		if (i == sim.num - 1)
			cdr.dx = &dongles[0];
		else
			cdr.dx = &dongles[i + 1];
		coders[i] = cdr;
		i++;
	}
	return (coders);
}

t_sim	create_sim(char **argv)
{
	t_sim	sim;

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
		return (sim.error = 1, sim);
	ft_strlcpy(sim.scheduler, argv[8], strlen(argv[8]) + 1);
	sim.dongles = malloc(sizeof(t_dongle) * sim.num);
	if (!sim.dongles)
		return (sim.error = 1, sim);
	sim.dongles = create_dongles(sim, sim.dongles);
	if (!sim.dongles)
		return (sim.error = 1, sim);
	sim.coders = malloc(sizeof(t_coder) * sim.num);
	if (!sim.coders)
		return (sim.error = 1, sim);
	sim.coders = create_coders(sim, sim.coders, sim.dongles);
	return (sim.error = 0, sim);
}

t_monitor	create_monitor(t_sim sim)
{
	t_monitor	monitor;

	monitor.error = 0;
	monitor.sim = sim;
	if (monitor.sim.error != 0)
		monitor.error = 1;
	return (monitor);
}

t_heap	create_heap(int n, char *scheduler)
{
	t_heap	heap;

	heap.size = n;
	heap.coders = malloc(sizeof(t_coder) * heap.size);
	if (!heap.coders)
		return (heap.error = 1, heap);
	heap.deadline = 0;
	ft_strlcpy(heap.scheduler, scheduler, strlen(scheduler));
	return (heap.error = 0, heap);
}
