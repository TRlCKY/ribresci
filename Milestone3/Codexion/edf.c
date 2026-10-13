/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 17:11:00 by ribresci          #+#    #+#             */
/*   Updated: 2026/10/13 15:53:48 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

// Dopo il controllo del burnout vengono effettuate le varie azioni
void	*use_dongle_edf(void *arg)
{
	t_coder		*coder;

	coder = (t_coder *)arg;
	if (coder->sx == NULL)
		return (one_coder(coder));
	while (coder->n_compile != 0 && coder->error != 1)
	{
		if (can_take_both(coder) == 0)
		{
			if (coder->error == 1 || start_compiling(coder) == 1)
				return (NULL);
			if (coder->error == 1 || release_dongles(coder, 1) == 1)
				return (NULL);
			if (coder->error == 1 || start_debugging(coder) == 1)
				return (NULL);
			if (coder->error == 1 || start_refactoring(coder) == 1)
				return (NULL);
		}
	}
	return (NULL);
}
