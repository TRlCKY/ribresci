/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:23:05 by ribresci          #+#    #+#             */
/*   Updated: 2025/12/18 18:21:34 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
/*
void	*ft_memchr(const void *s, int c, size_t n);

int	main()
{
	const char	s[] = "1234567890123";
	int			c;
	size_t		n;
	char		*z;

	c = '2';
	n = 13;
	printf("s:%s\n", s);
	z = ft_memchr(s, c, n);
	printf("z:%s\n", z);
	return (0);
}
*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;

	if (!s)
		return (NULL);
	str = (char *)s;
	while (str && n > 0)
	{
		if (*str == (char )c)
			return (str);
		str++;
		n--;
	}
	return (NULL);
}
