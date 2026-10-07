/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_action1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 12:41:48 by ribresci          #+#    #+#             */
/*   Updated: 2026/10/06 14:53:18 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	release_dongle_dx(t_coder *coder)
{
	pthread_mutex_lock(&coder->dx->mutex);
	coder->dx->used = 0;
	coder->dx->cooldown_time = current_time(coder->start) + coder->dx->cooldown;
	pthread_cond_broadcast(&coder->dx->cond);
	pthread_mutex_unlock(&coder->dx->mutex);
	return (0);
}

int	release_dongle_sx(t_coder *coder)
{
	pthread_mutex_lock(&coder->sx->mutex);
	coder->sx->used = 0;
	coder->sx->cooldown_time = current_time(coder->start) + coder->sx->cooldown;
	pthread_cond_broadcast(&coder->sx->cond);
	pthread_mutex_unlock(&coder->sx->mutex);
	return (0);
}
