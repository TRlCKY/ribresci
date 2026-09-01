/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fifo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 12:20:26 by ribresci          #+#    #+#             */
/*   Updated: 2026/09/01 15:14:45 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

/*
* Number of coders and dongles
*
* Time to burnout(If a coder did not start compiling within
* time_to_burnout milliseconds since the beginning of their last compile
* or the beginning of the simulation, they burn out.)
*
* Time to compile(During that time, they must hold two dongles)
*
* Time to debug(The time a coder will spend debugging)
*
* Time to refactor(After completing the refactoring phase, the coder will attempt
* to acquire dongles and start compiling again.)
*
* Number of compiles required(If all coders have compiled at least this
* many times, the simulation stops. Otherwise, it stops when a coder burns
* out)
*
* Dongle cooldown(After being released, a dongle is unavailable until its
* cooldown has passed)
*
* Scheduler(first_in_first_out/earliest_deadline_first=
* last_compile_start + time_to_burnout)
*/

int	fifo(int *array)
{
	struct coder	*coders;
	struct dongle	*dongles;

	dongles = malloc(sizeof(struct dongle) * array[0]);
	if (!dongles)
		return (1);
	dongles = create_dongles(array, dongles);
	coders = malloc(sizeof(struct coder) * array[0]);
	if (!coders)
		return (1);
	coders = create_coders(array, coders, dongles);
	return (0);
}
