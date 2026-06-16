/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:23:05 by ribresci          #+#    #+#             */
/*   Updated: 2025/12/04 11:57:41 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>

int	ft_isprint(int c);

int	main(void)
{
	int	c;
	int		x;

	str = "Hell\nre";
	x = ft_isprint(str);
	printf("\n%d", x);
	str = "";
	x = ft_isprint(str);
	printf("\n%d", x);
	str = "Hello_There123";
	x = ft_isprint(str);
	printf("\n%d", x);
	return (0);
}
*/
int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
