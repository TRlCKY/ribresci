/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 14:51:00 by ribresci          #+#    #+#             */
/*   Updated: 2026/10/14 11:00:18 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

t_dongle	*create_dongles(char **argv, t_dongle *dongles)
{
	int			i;

	i = 0;
	while (i != atoi(argv[0]))
	{
		dongles[i].id = i + 1;
		dongles[i].cooldown = atoi(argv[6]);
		dongles[i].used = 0;
		if (pthread_mutex_init(&dongles[i].mutex, NULL) != 0)
			return (NULL);
		if (pthread_cond_init(&dongles[i].cond, NULL) != 0)
			return (NULL);
		dongles[i].heap = create_heap(atoi(argv[0]), argv[7]);
		dongles[i].cooldown_time = 0;
		i++;
	}
	return (dongles);
}

t_coder	*create_coders(t_sim *sim, t_coder *coders, t_dongle *dongles)
{
	int		i;

	i = -1;
	while (++i != sim->num)
	{
		coders[i].start = sim->start;
		coders[i].id = i + 1;
		coders[i].burnout = sim->burnout;
		coders[i].compile = atoi(sim->argv[0]);
		coders[i].debug = atoi(sim->argv[1]);
		coders[i].refactor = atoi(sim->argv[2]);
		coders[i].n_compile = atoi(sim->argv[3]);
		coders[i].last_compile_start = current_time(sim->start);
		pthread_mutex_init(coders[i].mutex, NULL);
		if (sim->num > 1)
			coders[i].sx = &dongles[i];
		else
			coders[i].sx = NULL;
		if (i == sim->num - 1)
			coders[i].dx = &dongles[0];
		else
			coders[i].dx = &dongles[i + 1];
		coders[i].error = 0;
	}
	return (coders);
}

t_sim	create_sim(char **argv)
{
	t_sim	sim;

	clock_gettime(CLOCK_MONOTONIC, &sim.start);
	sim.num = atoi(argv[1]);
	sim.burnout = atoi(argv[2]);
	sim.argv = malloc(sizeof(char *) * (5));
	sim.argv = get_argv(&sim, argv);
	if (sim.error == 1)
		return (sim);
	sim.cooldown = atoi(argv[7]);
	sim.scheduler = malloc(sizeof(char) * (strlen(argv[8]) + 1));
	if (!sim.scheduler)
		return (sim.error = 1, sim);
	ft_strlcpy(sim.scheduler, argv[8], strlen(argv[8]) + 1);
	sim.dongles = malloc(sizeof(t_dongle) * sim.num);
	if (!sim.dongles)
		return (sim.error = 1, sim);
	sim.dongles = create_dongles(argv, sim.dongles);
	if (!sim.dongles)
		return (sim.error = 1, sim);
	sim.coders = malloc(sizeof(t_coder) * sim.num);
	if (!sim.coders)
		return (sim.error = 1, sim);
	sim.coders = create_coders(&sim, sim.coders, sim.dongles);
	return (sim.error = 0, sim);
}

t_monitor	create_monitor(t_sim *sim, t_dongle *dongles)
{
	t_monitor	monitor;

	monitor.error = 0;
	monitor.sim = sim;
	if (monitor.sim->error != 0)
		monitor.error = 1;
	else
		monitor.error = 0;
	monitor.finish = 1;
	monitor.dongles = dongles;
	return (monitor);
}

t_heap	create_heap(int n, char *scheduler)
{
	t_heap	heap;

	heap.size = 0;
	heap.capacity = n;
	heap.coders = malloc(sizeof(t_coder) * n);
	if (!heap.coders)
		return (heap.error = 1, heap);
	if (pthread_mutex_init(&heap.mutex, NULL) != 0)
		return (heap.error = 1, heap);
	heap.scheduler = malloc(sizeof(char) * (strlen(scheduler) + 1));
	if (!heap.scheduler)
		return (heap.error = 1, heap);
	ft_strlcpy(heap.scheduler, scheduler, strlen(scheduler) + 1);
	return (heap.error = 0, heap);
}
