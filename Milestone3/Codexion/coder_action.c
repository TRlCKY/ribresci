/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 17:12:37 by ribresci          #+#    #+#             */
/*   Updated: 2026/10/20 12:32:27 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

// Prende la chiavetta alla sua destra se ci sono le condizioni per farlo
int	take_dongle(t_coder *cdr, t_dongle *d)
{
	add_back(&d->heap, cdr);
	if (cdr->error == 1)
		return (pthread_mutex_unlock(&d->mutex), 1);
	pop_front(&d->heap);
	print_msg(cdr, "has taken a dongle\n");
	d->used = 1;
	pthread_mutex_unlock(&d->mutex);
	return (0);
}

// Calcola il tempo di attesa se la chiavetta e' ancora in cooldown
// struct timespec	calculate_time(long time)
// {
// 	struct timespec	deadline;

// 	clock_gettime(CLOCK_REALTIME, &deadline);
// 	deadline.tv_sec += time / 1000;
// 	deadline.tv_nsec += (time % 1000) * 1000000L;
// 	if (deadline.tv_nsec >= 1000000000L)
// 	{
// 		deadline.tv_sec++;
// 		deadline.tv_nsec -= 1000000000L;
// 	}
// 	return (deadline);
// }
