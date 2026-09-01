#ifndef CODEDXION_H
# define CODEXION_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

struct dongle{
	int	id;
	int	cooldown;
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

int		fifo(int *array);
int		edf(int *array);
int		check_values(int argc, char **argv);
void	check_burnout(void);
int		use_dongle(long now, long time, int num, int i);
void	current_time(void);
#endif;
