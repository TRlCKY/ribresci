/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 10:57:28 by ribresci          #+#    #+#             */
/*   Updated: 2026/10/16 11:24:46 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

// Stampa i vari messaggi
void	print_msg(t_coder *coder, char *msg)
{
	pthread_mutex_lock(coder->mutex);
	if (coder->error == 0)
		printf("%ld %d %s", current_time(coder->start), coder->id, msg);
	pthread_mutex_unlock(coder->mutex);
}
