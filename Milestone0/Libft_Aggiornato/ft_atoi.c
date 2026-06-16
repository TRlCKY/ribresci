/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:23:05 by ribresci          #+#    #+#             */
/*   Updated: 2025/12/18 18:20:31 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>

int	ft_atoi(char *str);

int	main(void){
	char	*str = "   --+--12345abc";
	char	*str1 = "   \t---+ --12345abc";
	char	*str2 = "   -12345abc";
	int		x;

	x = ft_atoi(str);
	printf("\n%d\n", x);
	x = ft_atoi(str1);
	printf("\n%d\n", x);
	x = ft_atoi(str2);
	printf("\n%d\n", x);
	return (0);
}
*/
int	ft_atoi(const char *str)
{
	int	i;
	int	n;
	int	count;

	i = 0;
	n = 0;
	count = 1;
	if (!str)
		return (0);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			count *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		n = (n * 10) + (str[i] - 48);
		i++;
	}
	return (n * count);
}
