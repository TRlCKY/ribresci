/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 16:42:16 by ribresci          #+#    #+#             */
/*   Updated: 2026/10/05 14:57:24 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEXION_H
# define CODEXION_H
# define _POSIX_C_SOURCE 199309L
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <string.h>
# include <time.h>

typedef struct s_dongle
{
	pthread_cond_t	cond;
	pthread_mutex_t	mutex;
	int				id;
	int				cooldown;
	int				used;
	int				error;
}	t_dongle;

typedef struct s_coder
{
	struct timespec	start;
	int				id;
	int				burnout;
	int				compile;
	int				debug;
	int				refactor;
	int				n_compile;
	int				error;
	int				last_compile_start;
	pthread_t		thread;
	pthread_mutex_t	print_mutex;
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
	int				error;
	t_coder			*coders;
	t_dongle		*dongles;
}	t_sim;

typedef struct s_heap
{
	pthread_mutex_t	mutex;
	int				size;
	t_coder			*coders;
	int				error;
	int				deadline;
	char			*scheduler;
}	t_heap;

typedef struct monitor
{
	pthread_t		*monitor_t;
	t_sim			sim;
	t_heap			heap;
	int				error;
}	t_monitor;

// fifo_edf
void			*use_dongle_fifo(void *arg);
void			*use_dongle_edf(void *arg);
void			*check(void *arg);
int				*check_coders(t_monitor *mntr, int finish);

// main
int				current_time(struct timespec start);
int				check_values(int argc, char **argv);
int				main(int argc, char **argv);
int				start(t_sim sim, t_monitor *monitor, char *scheduler);
int				start1(t_sim sim, t_monitor *monitor);

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
t_dongle		*create_dongles(t_sim sim, t_dongle *dongles);
t_coder			*create_coders(t_sim sim, t_coder *coders, t_dongle *dongles);
t_sim			create_sim(t_sim sim, char **argv);
t_monitor		create_monitor(t_monitor monitor, t_sim sim, t_heap heap);
t_heap			create_heap(t_heap heap, int n, char *scheduler);

// heap_operations
void			add_back(t_heap *heap, t_coder *coder);
void			pop_front(t_heap *heap);
void			sort_heap(t_heap *heap);
t_coder			*get_next(t_heap *heap);

// utilities
unsigned int	ft_strlcpy(char *dest, const char *src, size_t size);
void			freemonitor(t_monitor monitor);
void			freesim(t_sim sim);
void			freeheap(t_heap heap);
void			write_error(int id, int time);

#endif
