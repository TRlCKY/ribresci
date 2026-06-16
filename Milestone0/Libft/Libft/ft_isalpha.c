/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:23:05 by ribresci          #+#    #+#             */
/*   Updated: 2025/12/04 11:54:08 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>

int	ft_isalpha(char *str);

int	main(void)
{
	char	*str;
	int		x;

	str = "";
	x = ft_isalpha(str);
	printf("\n%d", x);
	str = "HelloThere";
	x = ft_isalpha(str);
	printf("\n%d", x);
	str = "123";
	x = ft_isalpha(str);
	printf("\n%d", x);
	return (0);
}
*/
int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}
