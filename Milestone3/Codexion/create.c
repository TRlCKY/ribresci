/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 14:51:00 by ribresci          #+#    #+#             */
/*   Updated: 2026/10/14 18:12:35 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	create_dongles(char **argv, t_dongle *dongles)
{
	int			i;

	i = 0;
	while (i != atoi(argv[1]))
	{
		if (pthread_cond_init(&dongles[i].cond, NULL) != 0)
			return (1);
		if (pthread_mutex_init(&dongles[i].mutex, NULL) != 0)
			return (1);
		dongles[i].id = i + 1;
		dongles[i].cooldown = atoi(argv[7]);
		dongles[i].cooldown_time = 0;
		dongles[i].used = 0;
		dongles[i].heap = create_heap(2, argv[8], atoi(argv[2]));
		if (dongles[i].heap.error == 1)
			return (1);
		i++;
	}
	return (0);
}

t_coder	*create_coders(t_sim *sim, t_coder *cdrs, t_dongle *dngls, char **argv)
{
	int		i;

	i = -1;
	while (++i != sim->num)
	{
		cdrs[i].start = sim->start;
		cdrs[i].id = i + 1;
		cdrs[i].compile = atoi(argv[3]);
		cdrs[i].debug = atoi(argv[4]);
		cdrs[i].refactor = atoi(argv[5]);
		cdrs[i].n_compile = atoi(argv[6]);
		cdrs[i].error = 0;
		cdrs[i].last_compile_start = current_time(sim->start);
		cdrs[i].mutex = sim->mutex;
		if (sim->num > 1)
			cdrs[i].sx = &dngls[i];
		else
			cdrs[i].sx = NULL;
		cdrs[i].dx = &dngls[(i + 1) % (sim->num)];
	}
	return (cdrs);
}

t_sim	create_sim(char **argv)
{
	t_sim	sim;

	memset(&sim, 0, sizeof(sim));
	clock_gettime(CLOCK_MONOTONIC, &sim.start);
	sim.num = atoi(argv[1]);
	sim.burnout = atoi(argv[2]);
	sim.cooldown = atoi(argv[7]);
	sim.scheduler = malloc(sizeof(char) * (strlen(argv[8]) + 1));
	if (!sim.scheduler)
		return (sim.error = 1, sim);
	ft_strlcpy(sim.scheduler, argv[8], strlen(argv[8]) + 1);
	if (create_sim1(&sim, argv) == 1)
		return (sim);
	return (sim);
}

int	create_sim1(t_sim *sim, char **argv)
{
	sim->mutex = malloc(sizeof(pthread_mutex_t));
	if (!sim->mutex)
		return (sim->error = 1, 1);
	if (pthread_mutex_init(sim->mutex, NULL) != 0)
		return (free(sim->mutex), sim->mutex = NULL, sim->error = 1, 1);
	sim->dongles = malloc(sizeof(t_dongle) * sim->num);
	if (!sim->dongles)
		return (sim->error = 1, 1);
	memset(sim->dongles, 0, sizeof(t_dongle) * sim->num);
	if (create_dongles(argv, sim->dongles) == 1)
		return (sim->error = 1, 1);
	sim->coders = malloc(sizeof(t_coder) * sim->num);
	if (!sim->coders)
		return (sim->error = 1, 1);
	memset(sim->coders, 0, sizeof(t_coder) * sim->num);
	sim->coders = create_coders(sim, sim->coders, sim->dongles, argv);
	return (sim->error = 0, 0);
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
