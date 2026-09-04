/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 12:15:14 by ribresci          #+#    #+#             */
/*   Updated: 2026/09/04 14:23:06 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

// Controlla se si verifica il burnout con ogni azione
int	check_burnout(t_coder coder0, struct timespec start, int time)
{
	int	now;

	now = current_time(start);
	if (now + time >= coder0.burnout)
	{
		printf("%d %d burned out\n", current_time(start), coder0.id);
		return (1);
	}
	return (0);
}

// Dopo il controllo del burnout vengono effettuate le varie azioni
int	use_dongle(t_sim sim, t_coder coder)
{
	if (check_burnout(coder, sim.start, 0) == 0)
		printf("%d %d has taken a dongle\n", current_time(sim.start), coder.id);
	else
		return (1);
	if (check_burnout(coder, sim.start, 0) == 0)
		printf("%d %d has taken a dongle\n", current_time(sim.start), coder.id);
	else
		return (1);
	if (check_burnout(coder, sim.start, coder.compile) == 0)
		printf("%d %d is compiling\n", current_time(sim.start), coder.id);
	else
		return (1);
	usleep(coder.compile);
	if (check_burnout(coder, sim.start, coder.debug) == 0)
		printf("%d %d is debugging\n", current_time(sim.start), coder.id);
	else
		return (1);
	usleep(coder.debug);
	if (check_burnout(coder, sim.start, coder.refactor) == 0)
		printf("%d %d is refactoring\n", current_time(sim.start), coder.id);
	else
		return (1);
	usleep(coder.refactor);
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
	if (strcmp(argv[argc -1], "fifo") != 0 && strcmp(argv[argc -1], "edf") != 0)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_sim		sim;
	t_monitor	monitor;
	int			i;

	i = 0;
	if (check_values(argc, argv) == 1)
		return (1);
	sim = create_sim(sim, argv);
	monitor = create_monitor(monitor, sim, sim.coders, sim.dongles);
	if (strncmp(sim.scheduler, "fifo") == 0)
		start(sim, monitor, 0);
	else
		start(sim, monitor, 1);
	freeall(sim);
	return (0);
}
