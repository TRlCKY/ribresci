/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:23:05 by ribresci          #+#    #+#             */
/*   Updated: 2025/12/18 15:43:28 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
/*
unsigned int	ft_strlcpy(char *dest, const char *src, size_t n);

int	main(void)
{
	char	src[] = "coucou";
	char	dest[] = "AAAAAAAAAA";
	size_t	size = 1;
	int		i = 0;
	int		e = 0;

	while (dest[i])
		i++;
	printf("%d, %s\n", ft_strlcpy(dest, src, size), dest);
	while (e < i)
	{
		if (dest[e] == 0)
			printf("_");
		printf("%c", dest[e]);
		e++;
	}
	printf("\n");
	return (0);
}
*/

unsigned int	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	e;

	i = 0;
	e = 0;
	if (src && dest)
	{
		while (src[e])
			e++;
		if (size > 0)
		{
			while (src[i] != '\0' && i < size - 1)
			{
				dest[i] = src[i];
				i++;
			}
			dest[i] = '\0';
		}
	}
	return (e);
}
