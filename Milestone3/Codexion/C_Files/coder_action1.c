/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_action1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 12:41:48 by ribresci          #+#    #+#             */
/*   Updated: 2026/10/05 16:34:43 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../H_Files/codexion.h"

int	release_dongle_dx(t_coder *coder)
{
	pthread_mutex_lock(&coder->dx->mutex);
	usleep(coder->dx->cooldown);
	coder->dx->used = 0;
	pthread_mutex_unlock(&coder->dx->mutex);
	pthread_cond_broadcast(&coder->dx->cond);
	return (0);
}

int	release_dongle_sx(t_coder *coder)
{
	pthread_mutex_lock(&coder->dx->mutex);
	usleep(coder->sx->cooldown);
	coder->sx->used = 0;
	pthread_mutex_unlock(&coder->sx->mutex);
	return (0);
}
