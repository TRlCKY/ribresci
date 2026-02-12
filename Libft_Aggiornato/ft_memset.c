/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:23:05 by ribresci          #+#    #+#             */
/*   Updated: 2025/11/24 16:51:25 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
/* #include <string.h>

void	*ft_memset(void *dest, int c, size_t n);

int	main()
{
	char	dest[] = "c";
	size_t	i;
	size_t	n;

	i = 0;
	n = 5;
	ft_memset(dest, 65, n);
	printf("%s\n", dest);
	memset(dest, 97, n);
	printf("%s\n", dest);
	return (0);
}
*/
void	*ft_memset(void *dest, int c, size_t n)
{
	size_t			i;
	unsigned char	x;
	unsigned char	*str;

	if (!dest)
		return (NULL);
	i = 0;
	x = c;
	str = dest;
	while (i < n)
	{
		*str = x;
		i++;
		str++;
	}
	str -= i + 1;
	return (str);
}
