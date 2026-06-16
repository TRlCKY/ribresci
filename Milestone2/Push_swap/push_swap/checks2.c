/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 11:45:38 by ribresci          #+#    #+#             */
/*   Updated: 2026/03/12 12:12:37 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error(void)
{
	write(2, "Error\n", 6);
	return (0);
}

int	numblen(int n)
{
	int	x;

	x = 0;
	if (n != 0)
	{
		while (n != 0)
		{
			n /= 10;
			x++;
		}
	}
	else
		return (1);
	return (x);
}
