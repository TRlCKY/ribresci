#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include "codexion.h"

// Dopo il controllo se c'è il burnout o meno a seconda del case viene effettuata l'azione e poi fatto passare il tempo
int use_dongle(long now, long time, int num, int i)
{
	switch (i) {
		case 1:
			printf("%d %d has taken a dongle", time, num);
			break;
		case 2:
			printf("%d %d is compiling", now, num);
			break;
		case 3:
			printf("%d %d is debugging", now, num);
			break;
		case 4:
			printf("%d %d is refactoring", now, num);
			break;
	}
	usleep(time);
	return (0);
}

long current_time(struct timeval time0)
{
	struct timeval	time;
	long			sec, usec;

	gettimeofday(&time, NULL);
	sec = time.tv_sec - time0.tv_sec;
	usec = time.tv_usec - time0.tv_usec;
	return (sec * 1000 + usec / 1000);
}

// Controlla se si verifica il burnout, altrimenti si usano le chiavette e poi si apetta il cooldown per riusarle
void check_burnout(int num, pthread_t thread, struct timeval time0, long deadline, int *array)
{
	long now;

	now = current_time(time0);
	if (now < deadline)
		use_dongle(now, 0, num, 1);
	else
		printf("%d %d burned out", now, num);
	if (now < deadline)
		use_dongle(now, 0, num, 1);
	else
		printf("%d %d burned out", now, num);
	if (now + array[2] < deadline)
		use_dongle(now, array[2], num, 2);
	else
		printf("%d %d burned out", now, num);
	if (now + array[3] < deadline)
		use_dongle(now, array[3], num, 3);
	else
		printf("%d %d burned out", now, num);
	if (now + array[4] < deadline)
		use_dongle(now, array[4], num, 4);
	else
		printf("%d %d burned out", now, num);
	usleep(array[6]);
}

int check_values(int argc, char **argv)
{
	int i;
	int n;

	i = 1;
	if (argc != 9)
		return (1);
	while (i != argc - 1)
	{
		n = atoi(argv[i]);
		// Se e' minore di 0 o se l'atoi fallisce e il numero in forma di stringa e' diverso da 0
		if (n < 0 || (n == 0 && strcmp(argv[i], "0") != 0))
			return (1);
		i++;
	}
	if (strcmp(argv[argc -1], "fifo") != 0 && strcmp(argv[argc -1], "edf") != 0)
		return (1);
	return (0);
}

int main(int argc, char **argv)
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
