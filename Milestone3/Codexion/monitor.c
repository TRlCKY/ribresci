/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 17:13:08 by ribresci          #+#    #+#             */
/*   Updated: 2026/10/12 17:22:34 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

// Controlla che i coders non vadano in burnout o abbiano finito
void	*check(void *arg)
{
	t_monitor	*m;
	int			i;

	m = (t_monitor *)arg;
	while (m->finish)
	{
		i = -1;
		while (++i < m->sim->num)
		{
			if (m->sim->coders[i].n_compile != 0 && check_time(m, i))
			{
				stop_coders(m, m->sim->coders[i].id);
				i = m->sim->num;
			}
			if (check_coders(m) == 0)
			{
				m->finish = 0;
				i = m->sim->num;
			}
		}
		usleep(1000);
	}
	return (NULL);
}

// Con un burnout si fermano tutti
void	stop_coders(t_monitor *m, int id)
{
	int	i;

	i = 0;
	print_er(current_time(m->sim->start), id);
	m->finish = 0;
	while (i < m->sim->num)
	{
		m->sim->coders[i].error = 1;
		i++;
	}
	i = 0;
	while (i < m->sim->num)
	{
		pthread_mutex_lock(&m->sim->dongles[i].mutex);
		pthread_cond_broadcast(&m->sim->dongles[i].cond);
		pthread_mutex_unlock(&m->sim->dongles[i].mutex);
		i++;
	}
}

// Controlla che abbiano finito di compilare tutti
int	check_coders(t_monitor *mntr)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (i < mntr->sim->num)
	{
		if (mntr->sim->coders[i].n_compile == 0)
			x++;
		i++;
	}
	if (x == mntr->sim->num)
		return (0);
	return (1);
}

// Controlla che non vadano in burnout
int	check_time(t_monitor *mntr, int i)
{
	if (current_time(mntr->sim->start)
		- mntr->sim->coders[i].last_compile_start
		>= mntr->sim->coders[i].burnout)
		return (1);
	return (0);
}

// Stampa l'errore
void	print_er(int time, int id)
{
	fprintf(stderr, "%d %d burned out\n", time, id);
}
