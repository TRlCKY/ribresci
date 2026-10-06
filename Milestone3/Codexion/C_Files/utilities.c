/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 16:45:49 by ribresci          #+#    #+#             */
/*   Updated: 2026/10/06 12:19:14 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../H_Files/codexion.h"

unsigned int	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	e;

	i = 0;
	e = 0;
	if (src && dest)
	{
		while (src[e])
			e++;
		if (size > 0)
		{
			while (src[i] != '\0' && i < size - 1)
			{
				dest[i] = src[i];
				i++;
			}
			dest[i] = '\0';
		}
	}
	return (e);
}

void	freemonitor(t_monitor monitor)
{
	if (monitor.sim.coders)
		free(monitor.sim.coders);
	if (monitor.sim.dongles)
		free(monitor.sim.dongles);
	freesim(monitor.sim);
}

void	freesim(t_sim sim)
{
	if (sim.coders)
		free(sim.coders);
	if (sim.dongles)
		free(sim.dongles);
	if (sim.scheduler)
		free(sim.scheduler);
}

void	freeheap(t_heap heap)
{
	if (heap.coders)
		free(heap.coders);
}

// Stampa quando un coder arriva al burnout
void	write_error(int id, int time)
{
	char	msg[64];
	int		i;
	int		e;

	i = 0;
	e = 0;
	while (i < strlen((char *)id))
		msg[i++] = ((char *)id)[i];
	msg[i++] = ' ';
	while (i < strlen((char *)time))
		msg[i++] = ((char *)id)[e++];
	msg[i++] = ' ';
	msg[i++] = 'b';
	msg[i++] = 'u';
	msg[i++] = 'r';
	msg[i++] = 'n';
	msg[i++] = 'e';
	msg[i++] = 'd';
	msg[i++] = ' ';
	msg[i++] = 'o';
	msg[i++] = 'u';
	msg[i++] = 't';
	msg[i++] = '\n';
	msg[i++] = '\0';
	write(2, msg, strlen(msg));
}
