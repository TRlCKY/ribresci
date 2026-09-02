#ifndef CODEDXION_H
# define CODEXION_H
# define _POSIX_C_SOURCE 199309L
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <time.h>

typedef struct s_dongle{
	int	id;
	int	cooldown;
	int	used;
} t_dongle;

typedef struct s_coder{
	int			id;
	int			burnout;
	int			compile;
	int			debug;
	int			refactor;
	int			n_compile;
	pthread_t	thread;
	t_dongle	dx;
	t_dongle	sx;
} t_coder;

typedef struct s_sim{
	int			num;
	int			burnout;
	int			compile;
	int			debug;
	int			refactor;
	int			n_compile;
	int			cooldown;
	t_coder		*coders;
	t_dongle	*dongles;
} t_sim;

int			fifo(int *array);
int			edf(int *array);
int			check_values(int argc, char **argv);
int			check_burnout(t_coder coder0, struct timespec start, int time);
int			use_dongle(struct timespec start, t_coder cdr);
int			current_time(struct timespec start);
t_dongle	*create_dongles(t_sim sim, t_dongle *dongles);
t_coder		*create_coders(t_sim sim, t_coder *coders, t_dongle *dongles);
t_sim		create_sim(t_sim sim, int *array);

#endif
