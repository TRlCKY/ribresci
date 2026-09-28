/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_action1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 12:41:48 by ribresci          #+#    #+#             */
/*   Updated: 2026/09/28 18:19:02 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../H_Files/codexion.h"

int	release_dongle_dx(t_coder coder)
{
	sleep(coder.dx.cooldown);
	coder.dx.used = 0;
	pthread_mutex_unlock(&coder.dx.mutex);
	if (check_burnout(coder, coder.start, 0) == 1)
	{
		coder.error = 1;
		return (1);
	}
	return (0);
}

int	release_dongle_sx(t_coder coder)
{
	sleep(coder.sx.cooldown);
	coder.sx.used = 0;
	pthread_mutex_unlock(&coder.sx.mutex);
	if (check_burnout(coder, coder.start, 0) == 1)
	{
		coder.error = 1;
		return (1);
	}
	return (0);
}
