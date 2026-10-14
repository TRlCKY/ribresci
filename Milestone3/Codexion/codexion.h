/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 16:42:16 by ribresci          #+#    #+#             */
/*   Updated: 2026/10/14 17:28:19 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEXION_H
# define CODEXION_H
# define _POSIX_C_SOURCE 199309L
# define _XOPEN_SOURCE 500
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <string.h>
# include <time.h>

typedef struct s_coder	t_coder;

// size e' la dimensione attuale, capacity quella massima
typedef struct s_heap
{
	pthread_mutex_t	mutex;
	int				size;
	int				capacity;
	t_coder			**coders;
	int				error;
	char			*scheduler;
	int				burnout;
}	t_heap;

// cooldown e' il cooldown della dongle, cooldown_time indice quando sara' di
// di nuovo disponibile
typedef struct s_dongle_
{
	pthread_cond_t	cond;
	pthread_mutex_t	mutex;
	int				id;
	int				cooldown;
	long			cooldown_time;
	int				used;
	int				error;
	t_heap			heap;
}	t_dongle;

typedef struct s_coder
{
	struct timespec	start;
	pthread_mutex_t	*mutex;
	pthread_cond_t	*cond;
	int				id;
	int				compile;
	int				debug;
	int				refactor;
	int				n_compile;
	int				order;
	int				error;
	long			last_compile_start;
	pthread_t		thread;
	t_dongle		*dx;
	t_dongle		*sx;
}	t_coder;

typedef struct s_sim
{
	struct timespec	start;
	pthread_mutex_t	*mutex;
	pthread_cond_t	*cond;
	int				num;
	int				burnout;
	int				cooldown;
	char			*scheduler;
	int				error;
	int				stop;
	t_coder			*coders;
	t_dongle		*dongles;
}	t_sim;

typedef struct monitor
{
	pthread_t		monitor_t;
	t_sim			*sim;
	t_dongle		*dongles;
	int				error;
	int				finish;
}	t_monitor;

// fifo
void			*use_dongle_fifo(void *arg);
void			*fifo1(void *arg);
void			*one_coder(void *arg);
int				can_take_both(t_coder *coder);

// edf
void			*use_dongle_edf(void *arg);

// monitor
void			*check(void *arg);
void			stop_coders(t_monitor *m, int id);
int				check_coders(t_monitor *mntr);
int				check_time(t_monitor *mntr, int i);
void			print_er(int time, int id);

// main
long			current_time(struct timespec start);
int				check_values(int argc, char **argv);
int				main(int argc, char **argv);
int				start(t_sim *sim, t_monitor *monitor, char *scheduler);
int				start1(t_sim *sim, t_monitor *monitor);

// coder action
int				take_dongle_dx(t_coder *coder);
int				take_dongle_dx1(t_coder *coder);
int				take_dongle_sx(t_coder *coder);
int				take_dongle_sx1(t_coder *coder);
struct timespec	calculate_time(long time);

// coder action 1
int				release_dongles(t_coder *coder, int n);
int				start_compiling(t_coder *coder);
int				start_debugging(t_coder *coder);
int				start_refactoring(t_coder *coder);

// create
int				create_dongles(char **argv, t_dongle *dongles);
t_coder			*create_coders(t_sim *sim, t_coder *coders, t_dongle *dongles,
					char **argv);
t_sim			create_sim(char **argv);
int				create_sim1(t_sim *sim, char **argv);
t_monitor		create_monitor(t_sim *sim, t_dongle *dongles);

// create1
t_heap			create_heap(int n, char *scheduler, int burnout);

// heap_operations
void			add_back(t_heap *heap, t_coder *coder);
void			pop_front(t_heap *heap);
void			sort_heap(t_heap *heap);
int				do_switch(t_coder *c1, t_coder *c2, int burnout);
int				is_inside(t_heap *heap, t_coder coder);

// heap_operations1
t_coder			*get_next(t_heap *heap);

// utilities
unsigned int	ft_strlcpy(char *dest, const char *src, size_t size);
void			freesim(t_sim *sim);
void			freeheap(t_heap *heap);
char			**get_argv(t_sim *sim, char **argv);

#endif
