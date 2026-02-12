/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:23:05 by ribresci          #+#    #+#             */
/*   Updated: 2025/12/18 18:22:16 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
/*
void	*ft_memcpy(void *dest, const void *src, size_t n);

int	main()
{
	char	src[] = "1234567890";
	char	dest[100] = "0";
	size_t	n = 3;

	ft_memcpy(dest, src, n);
	printf("%s\n", src);
	printf("%s\n", dest);
	return (0);
}
*/
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*s;
	char		*d;

	s = src;
	d = dest;
	while (n > 0)
	{
		*d = *s;
		s++;
		d++;
		n--;
	}
	return (dest);
}
