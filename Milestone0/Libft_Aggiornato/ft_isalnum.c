/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:23:05 by ribresci          #+#    #+#             */
/*   Updated: 2025/12/04 11:56:29 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>

int	ft_isalnum(int c);

int	main(void)
{
	char	c;
	int		x;

	str = "Hell\nre";
	x = ft_isalnum(str);
	printf("\n%d", x);
	str = "";
	x = ft_isalnum(str);
	printf("\n%d", x);
	str = "Hello_There123";
	x = ft_isalnum(str);
	printf("\n%d", x);
	return (0);
}
*/
int	ft_isalnum(int c)
{
	if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90)
		|| (c >= 97 && c <= 122))
		return (1);
	return (0);
}
