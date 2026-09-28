/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 12:15:14 by ribresci          #+#    #+#             */
/*   Updated: 2026/09/28 18:01:52 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../H_Files/codexion.h"

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
int	check_values(int argc, char *argv)
{
	int	i;
	int	n;

	i = 1;
	if (argc != 9)
		return (1);
	while (i != argc - 1)
	{
		n = atoi(&argv[i]);
		if (n < 0 || (n == 0 && strcmp(&argv[i], "0") != 0))
			return (1);
		i++;
	}
	if (strcmp(&argv[argc -1], "fifo") != 0
		&& strcmp(&argv[argc -1], "edf") != 0)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_sim		*sim;
	t_monitor	*monitor;
	t_heap		*heap;
	int			x;

	if (check_values(argc, *argv) == 1)
		return (1);
	sim = NULL;
	monitor = NULL;
	*heap = create_heap(*heap, argv[0]);
	*sim = create_sim(*sim, *argv);
	*monitor = create_monitor(*monitor, *sim, *heap);
	x = start(*sim, monitor, 1);
	if ((*monitor).error == 1)
	{
		freemonitor(*monitor);
		return (1);
	}
	(*monitor);
	return (0);
}
