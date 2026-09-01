/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 14:51:00 by ribresci          #+#    #+#             */
/*   Updated: 2026/09/01 15:46:06 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

struct dongle	*create_dongles(int *array, struct dongle *dongles)
{
	struct dongle	dngl;
	int				i;

	i = 0;
	while (i != array[0])
	{
		dngl.id = i + 1;
		dngl.cooldown = array[6];
		dngl.used = 0;
		dongles[i] = dngl;
		i++;
	}
}
