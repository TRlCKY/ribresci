/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 12:15:14 by ribresci          #+#    #+#             */
/*   Updated: 2026/09/02 17:01:48 by ribresci         ###   ########.fr       */
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
int	use_dongle(struct timespec start, t_coder cdr)
{
	if (check_burnout(cdr, start, 0) == 0)
		printf("%d %d has taken a dongle\n", current_time(start), cdr.id);
	else
		return (1);
	if (check_burnout(cdr, start, 0) == 0)
		printf("%d %d has taken a dongle\n", current_time(start), cdr.id);
	else
		return (1);
	if (check_burnout(cdr, start, cdr.compile) == 0)
		printf("%d %d is compiling\n", current_time(start), cdr.id);
	else
		return (1);
	usleep(cdr.compile);
	if (check_burnout(cdr, start, cdr.debug) == 0)
		printf("%d %d is debugging\n", current_time(start), cdr.id);
	else
		return (1);
	usleep(cdr.debug);
	if (check_burnout(cdr, start, cdr.refactor) == 0)
		printf("%d %d is refactoring\n", current_time(start), cdr.id);
	else
		return (1);
	usleep(cdr.refactor);
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
	t_sim			sim;
	int				*array;
	int				i;
	int				len;

	i = 0;
	if (check_values(argc, argv) == 1)
		return (1);
	array = create_array(argc, argv);
	len = strlen(array[7]);
	create_sim(sim, array, len);
	return (0);
}
