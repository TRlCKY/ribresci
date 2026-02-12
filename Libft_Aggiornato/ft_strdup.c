/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:49:22 by ribresci          #+#    #+#             */
/*   Updated: 2025/12/17 17:11:03 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
/*
#include <stdio.h>

char	*ft_strdup(const char *src);

int	main()
{
	const char	src[] = "coucou";
	char		*dest = ft_strdup(src);

	printf("%s\n", src);
	printf("%s\n", dest);
	free(dest);
	return (0);
}
*/
char	*ft_strdup(const char *src)
{
	char	*dest;
	int		i;
	int		e;

	i = 0;
	e = 0;
	while (src[i])
		i++;
	dest = (char *)malloc((i + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (e < i)
	{
		dest[e] = src[e];
		e++;
	}
	dest[e] = '\0';
	return (dest);
}
