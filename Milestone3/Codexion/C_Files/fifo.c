/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fifo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 12:20:26 by ribresci          #+#    #+#             */
/*   Updated: 2026/09/01 12:48:05 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include "codexion.h"

/*
*
* Number of coders and dongles(are the same number.
* coder-dongle-coder-dongle-coder...)
*
* Time to burnout(If a coder did not start compiling within
* time_to_burnout milliseconds since the beginning of their last compile
* or the beginning of the simulation, they burn out.)
*
* Time to compile( The time it takes for a coder to compile. During that
* time, they must hold two dongles)
*
* Time to debug(The time a coder will spend debugging)
*
* Time to refactor( The time a coder will spend refactoring. After 
* completing the refactoring phase, the coder will immediately attempt to
* acquire dongles and start compiling again.)
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
*
*/

struct coder	*create_coders(int *array, struct coder *coders)
{
	struct coder	cdr;
	int				i;

	i = 0;
	while (i != array[0])
	{
		cdr.id = i + 1;
		cdr.burnout = array[1];
		cdr.compile = array[2];
		cdr.debug = array[3];
		cdr.refactor = array[4];
		cdr.n_compile = array[5];
		coders[i] = cdr;
		i++;
	}
	return (coders);
}

struct dongle	*create_dongles(int *array, struct dongle *dongles)
{
	struct dongle	dngl;
	int				i;

	i = 0;
	while (i != array[0])
	{
		dngl.id = i + 1;
		dngl.cooldown = array[6];
		dongles[i] = dngl;
		i++;
	}
}

int	fifo(int *array)
{
	struct coder	*coders;
	struct dongle	*dongles;

	coders = malloc(sizeof(struct coder) * array[0]);
	if (!coders)
		return (1);
	coders = create_coders(array, coders);
	dongles = malloc(sizeof(struct dongle) * array[0]);
	if (!dongles)
		return (1);
	return (0);
}
