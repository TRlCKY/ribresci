/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:23:05 by ribresci          #+#    #+#             */
/*   Updated: 2025/12/18 18:31:47 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
/*
void	*ft_memmove(void *dest, const void *src, size_t n);

int	main()
{
	// char	s[] = {65, 66, 67, 68, 69, 0, 45};
	// char	s0[] = {0,  0,  0,  0,  0,  0, 0};
	// char	sCpy[] = {65, 66, 67, 68, 69, 0, 45};
	char    sResult[]  = {'C', 'D', 'C', 'D', 'E', '\0', '-'};
	char    sResult2[] = {'C', 'C', 'D', 'D', 'E', '\0', '-'};

	printf("%s, %s\n", sResult, sResult2);
	ft_memmove(sResult + 1, sResult, 3);
	printf("%s, %s\n", sResult, sResult2);
	return (0);
}
*/
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;
	unsigned char		r[100];
	size_t				i;

	i = 0;
	s = (unsigned const char *)src;
	d = (unsigned char *)dest;
	r[0] = '0';
	while (i < n)
	{
		r[i] = s[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		d[i] = r[i];
		i++;
	}
	return (d);
}
