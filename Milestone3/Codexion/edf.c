/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 17:11:00 by ribresci          #+#    #+#             */
/*   Updated: 2026/10/09 17:11:30 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

// Dopo il controllo del burnout vengono effettuate le varie azioni
void	*use_dongle_edf(void *arg)
{
	t_coder	*coder;

	coder = (t_coder *)arg;
	coder->burnout = 0;
	return (NULL);
}
