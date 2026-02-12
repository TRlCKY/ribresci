/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:23:05 by ribresci          #+#    #+#             */
/*   Updated: 2025/12/18 18:30:10 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
/*
unsigned int	ft_strlcat(char *dest, const char *src, size_t size);

int	main(void)
{
	char	src[] = "ciao";
	char	dest[11] = "123456789";
	int		i;
	int		size;
	size = 11;
	i = ft_strlcat(dest, src, size);
	printf("%s, %d\n", dest, i);
	size = 20;
	i = ft_strlcat(dest, src, size);
	printf("%s, %d\n", dest, i);
	return (0);
}
*/
unsigned int	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	e;
	size_t	x;

	i = 0;
	e = 0;
	while (dest[e])
		e++;
	while (src[i])
		i++;
	if (size <= e)
		return (size + i);
	x = 0;
	while (src[x] && (e + x +1) < size)
	{
		dest[e + x] = src[x];
		x++;
	}
	dest[e + x] = '\0';
	return (e + i);
}
