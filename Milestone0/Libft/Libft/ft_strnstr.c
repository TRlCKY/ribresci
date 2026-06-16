/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:23:05 by ribresci          #+#    #+#             */
/*   Updated: 2025/12/17 17:09:18 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
/*
char	*ft_strnstr(const char *big, const char *little, size_t len);

int	main(void)
{
	char const	*big = "aaabcabcd";
	char const	*little = "abcd";
	size_t		len = 9;

	printf("big: %s\n", big);
	printf("big: %s\n", ft_strnstr(big, little, len));
}
*/
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	e;

	i = 0;
	e = 0;
	if (*little == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		if (big[i++] == little[e])
			e++;
		else
		{
			i = i - e;
			e = 0;
			if (big[i] == little[e])
			{
				e++;
				i++;
			}
		}
		if (little[e] == '\0')
			return ((char *)&big[i - e]);
	}
	return (NULL);
}
