#ifndef CODEDXION_H
# define CODEXION_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

void	fifo(int *array);
void	edf(int *array);
int		check_values(int argc, char **argv);

#endif
