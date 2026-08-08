#ifndef CODEDXION_H
# define CODEXION_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

void	fifo(int *array);
void	edf(int *array);
int		check_values(int argc, char **argv);
void	check_burnout(int num, pthread_t thread, struct timeval time0, long deadline, int *array);
int		use_dongle(long now, long time, int num, int i);
long	current_time(struct timeval time0);
#endif
