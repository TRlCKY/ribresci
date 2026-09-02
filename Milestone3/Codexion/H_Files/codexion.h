/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 16:42:16 by ribresci          #+#    #+#             */
/*   Updated: 2026/09/02 17:28:40 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEXION_H
# define CODEXION_H
# define _POSIX_C_SOURCE 199309L
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <time.h>

typedef struct s_dongle
{
	int	id;
	int	cooldown;
	int	used;
}	t_dongle;

typedef struct s_coder
{
	int			id;
	int			burnout;
	int			compile;
	int			debug;
	int			refactor;
	int			n_compile;
	pthread_t	thread;
	t_dongle	dx;
	t_dongle	sx;
}	t_coder;

typedef struct monitor
{
	pthread_t	*monitor;
}	t_monitor;

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

// fifo
int				fifo(t_sim sim);

// edf
int				edf(t_sim sim);

// main
int				check_values(int argc, char **argv);
int				check_burnout(t_coder coder0, struct timespec start, int time);
int				use_dongle(struct timespec start, t_coder cdr);
int				current_time(struct timespec start);
int				main(int argc, char **argv);

// create
t_dongle		*create_dongles(t_sim sim, t_dongle *dongles);
t_coder			*create_coders(t_sim sim, t_coder *coders, t_dongle *dongles);
t_sim			create_sim(t_sim sim, int *array, int len);

// utilities
unsigned int	ft_strlcpy(char *dest, const char *src, size_t size);
int				*create_array(int argc, char **argv);

#endif
