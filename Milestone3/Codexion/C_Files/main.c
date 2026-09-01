/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 12:15:14 by ribresci          #+#    #+#             */
/*   Updated: 2026/09/01 12:35:06 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include "codexion.h"

// Dopo il controllo se c'è il burnout o meno a seconda del case viene 
// effettuata l'azione e poi fatto passare il tempo
int	use_dongle(long now, long time, int num, int i)
{
	if (i == 1)
		printf("%d %d has taken a dongle", time, num);
	if (i == 2)
		printf("%d %d is compiling", now, num);
	if (i == 3)
		printf("%d %d is debugging", now, num);
	if (i == 4)
		printf("%d %d is refactoring", now, num);
	usleep(time);
	return (0);
}

void	current_time(void)
{
	return ;
}

// Controlla se si verifica il burnout, altrimenti si usano le chiavette e poi
// si apetta il cooldown per riusarle
void	check_burnout(void)
{
	return ;
}

// Se e' minore di 0 o se l'atoi fallisce e il numero in forma di 
// stringa e' diverso da 0
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
	int	i;
	int	*array;

	i = 0;
	if (check_values(argc, argv) == 1)
		return (1);
	array = malloc((argc - 2) * sizeof(int));
	if (!array)
		return (NULL);
	while (i < argc - 2)
	{
		array[i] = atoi(argv[i]);
		i++;
	}
	if (strcmp(argv[argc -1], "fifo") == 0)
		fifo(array);
	if (strcmp(argv[argc -1], "edf") == 0)
		edf(array);
	return (0);
}
