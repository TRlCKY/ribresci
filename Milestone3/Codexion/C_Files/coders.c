/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coders.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 14:51:49 by ribresci          #+#    #+#             */
/*   Updated: 2026/09/01 14:52:00 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

struct coder	*create_coders(int *array, struct coder *coders,
	struct dongle *dongles)
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
		cdr.sx = dongles[i];
		if (i == array[0] - 1)
			cdr.dx = dongles[0];
		else
			cdr.dx = dongles[i + 1];
		coders[i] = cdr;
		i++;
	}
	return (coders);
}
