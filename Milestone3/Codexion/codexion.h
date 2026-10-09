/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 16:42:16 by ribresci          #+#    #+#             */
/*   Updated: 2026/10/09 18:00:48 by ribresci         ###   ########.fr       */
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
	t_coder			*coders;
	int				error;
	char			*scheduler;
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
	pthread_mutex_t	mutex;
	int				id;
	int				burnout;
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
	int				num;
	int				burnout;
	int				compile;
	int				debug;
	int				refactor;
	int				n_compile;
	int				cooldown;
	char			*scheduler;
	int				order;
	int				error;
	t_coder			*coders;
	t_dongle		*dongles;
}	t_sim;

typedef struct monitor
{
	pthread_t		monitor_t;
	t_sim			*sim;
	int				error;
	int				finish;
}	t_monitor;

// fifo
void			*use_dongle_fifo(void *arg);
void			*fifo1(void *arg);
void			*fifo_one_coder(void *arg);

// edf
void			*use_dongle_edf(void *arg);

// monitor
void			*check(void *arg);
void			stop_coders(t_monitor *m, int id);
int				check_coders(t_monitor *mntr);
int				check_time(t_monitor *mntr, int i);
void			print_er(int time, int id);

// main
int				current_time(struct timespec start);
int				check_values(int argc, char **argv);
int				main(int argc, char **argv);
int				start(t_sim *sim, t_monitor *monitor, char *scheduler);
int				start1(t_sim *sim, t_monitor *monitor);

// coder action
int				take_dongle_dx(t_coder *coder);
int				take_dongle_sx(t_coder *coder);
int				start_compiling(t_coder *coder);
int				start_debugging(t_coder *coder);
int				start_refactoring(t_coder *coder);

// coder action 1
int				release_dongle_dx(t_coder *coder);
int				release_dongle_sx(t_coder *coder);

// create
t_dongle		*create_dongles(t_sim *sim, t_dongle *dongles);
t_coder			*create_coders(t_sim *sim, t_coder *coders, t_dongle *dongles);
t_sim			create_sim(char **argv);
t_monitor		create_monitor(t_sim *sim);
t_heap			create_heap(int n, char *scheduler);

// heap_operations
void			add_back(t_heap *heap, t_coder *coder);
void			pop_front(t_heap *heap);
void			sort_heap(t_heap *heap);
t_coder			*get_next(t_heap *heap);
int				is_inside(t_heap *heap, t_coder coder);

// utilities
unsigned int	ft_strlcpy(char *dest, const char *src, size_t size);
void			freesim(t_sim *sim);
void			freeheap(t_heap *heap);

#endif
