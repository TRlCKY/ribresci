/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_action1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 12:41:48 by ribresci          #+#    #+#             */
/*   Updated: 2026/09/16 12:50:24 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	release_dongle_dx(t_coder coder)
{
	sleep(coder.dx.cooldown);
	coder.dx.used = 0;
	pthread_mutex_unlock(&coder.dx.mutex);
}

void	release_dongle_sx(t_coder coder)
{
	sleep(coder.sx.cooldown);
	coder.sx.used = 0;
	pthread_mutex_unlock(&coder.sx.mutex);
}
