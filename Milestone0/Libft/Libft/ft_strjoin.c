/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 10:52:04 by ribresci          #+#    #+#             */
/*   Updated: 2025/12/18 16:10:55 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
/*
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2);

int	main(void)
{
	char const	*s1 = "Gio";
	char const	*s2 = "rgio";

	printf("s1: %s\n", s1);
	printf("s2: %s\n", s2);
	printf("s3: %s\n", ft_strjoin(s1, s2));
	return (0);
}
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		e;

	if (!s1 && !s2)
		return (NULL);
	s3 = (char *)malloc(sizeof(char) * (ft_strlen((char *)s1)
				+ ft_strlen((char *)s2) + 1));
	if (!s3)
		return (NULL);
	i = 0;
	e = 0;
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[e])
	{
		s3[i] = s2[e];
		i++;
		e++;
	}
	s3[i] = '\0';
	return (s3);
}
