/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:23:05 by ribresci          #+#    #+#             */
/*   Updated: 2025/12/04 12:01:44 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>

int	ft_isascii(char *str);

int	main(void)
{
	char	*str;
	int		x;

	str = "Hell\nre";
	x = ft_isascii(str);
	printf("\n%d", x);
	str = "";
	x = ft_isascii(str);
	printf("\n%d", x);
	str = "Hello_There123";
	x = ft_isascii(str);
	printf("\n%d", x);
	return (0);
}
*/
int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
