/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:23:05 by ribresci          #+#    #+#             */
/*   Updated: 2025/12/04 11:54:13 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>

int	ft_isdigit(int c);

int	main(void)
{
	char	*str;
	int		x;

	str = "HelloThere";
	x = ft_isdigit(str);
	printf("\n%d", x);
	str = "";
	x = ft_isdigit(str);
	printf("\n%d", x);
	str = "123";
	x = ft_isdigit(str);
	printf("\n%d", x);
	return (0);
}
*/
int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}
