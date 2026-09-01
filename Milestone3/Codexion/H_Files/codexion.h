#ifndef CODEDXION_H
# define CODEXION_H
# define _POSIX_C_SOURCE 199309L
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <time.h>

struct dongle{
	int	id;
	int	cooldown;
	int	used;
};

struct coder{
	int				id;
	int				burnout;
	int				compile;
	int				debug;
	int				refactor;
	int				n_compile;
	struct dongle	dx;
	struct dongle	sx;
};

int				fifo(int *array);
int				edf(int *array);
int				check_values(int argc, char **argv);
int				check_burnout(struct coder coder0, struct timespec start, int time);
int				use_dongle(struct timespec start, struct coder *coders, int i);
int				current_time(struct timespec start);
struct dongle	*create_dongles(int *array, struct dongle *dongles);
struct coder	*create_coders(int *array, struct coder *coders,
	struct dongle *dongles);

#endif;
