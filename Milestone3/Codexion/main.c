/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 12:15:14 by ribresci          #+#    #+#             */
/*   Updated: 2026/10/06 14:52:55 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	start(t_sim sim, t_monitor *monitor, char *scheduler)
{
	int	i;

	i = 0;
	if (pthread_create(&monitor->monitor_t, NULL, check, monitor) != 0)
		return (1);
	while (i < sim.num)
	{
		if (strcmp(scheduler, "edf") == 0)
		{
			if (pthread_create(&sim.coders[i].thread, NULL, use_dongle_edf,
					&sim.coders[i]) != 0)
				return (1);
		}
		else
		{
			if (pthread_create(&sim.coders[i].thread, NULL, use_dongle_fifo,
					&sim.coders[i]) != 0)
				return (1);
		}
		i++;
	}
	return (start1(sim, monitor));
}

int	start1(t_sim sim, t_monitor *monitor)
{
	int	i;

	i = 0;
	pthread_join(monitor->monitor_t, NULL);
	if (monitor->error == 1)
		return (1);
	while (i < sim.num)
	{
		if (pthread_join(sim.coders[i].thread, NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}

int	current_time(struct timespec start)
{
	struct timespec	now;
	int				sec;
	int				nsec;

	clock_gettime(CLOCK_MONOTONIC, &now);
	sec = now.tv_sec - start.tv_sec;
	nsec = now.tv_nsec - start.tv_nsec;
	return ((sec * 1000) + (nsec / 1000000));
}

// Controlla che tutti i numeri siano positivi e se l'atoi li converte tutti
int	check_values(int argc, char **argv)
{
	int	i;
	int	n;

	i = 1;
	if (argc != 9)
		return (1);
	while (i != argc - 1)
	{
		n = atoi(argv[i]);
		if (n < 0 || (n == 0 && strcmp(argv[i], "0") != 0))
			return (1);
		i++;
	}
	if (strcmp(argv[argc -1], "fifo") != 0
		&& strcmp(argv[argc -1], "edf") != 0)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_sim		sim;
	t_monitor	monitor;
	t_heap		heap;
	int			x;

	if (check_values(argc, argv) == 1)
		return (1);
	heap = create_heap(atoi(argv[1]), argv[7]);
	if ((heap).error == 1)
		return (freeheap(heap), 1);
	sim = create_sim(argv);
	if ((sim).error == 1)
		return (freeheap(heap), freesim(sim), 1);
	monitor = create_monitor(sim);
	x = start(sim, &monitor, sim.scheduler);
	if ((monitor).error == 1)
		return (freeheap(heap), freesim(sim), freemonitor(monitor), 1);
	return (0);
}
