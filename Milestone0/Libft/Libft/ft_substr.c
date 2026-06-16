/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 10:37:06 by ribresci          #+#    #+#             */
/*   Updated: 2025/12/18 15:50:47 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
/*
#include <stdio.h>
#include <string.h>

char	*ft_substr(char const *s, unsigned int start, size_t len);

int	main(void)
{
	char	s[] = "tripouille";
	int		start = 100;
	size_t	len = 1;
	char	*s1 = ft_substr(s, start, len);

	printf("%s\n", s1);
	if (strcmp(s1, "\0") == 0)
		printf("Errore: %d\n", strcmp(s1, "\0"));
	else
		printf("Corretta: %s\n", s1);
	free(s1);
	return (0);
}
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) + 1 < start)
		return (ft_strdup("\0"));
	if (len == (size_t) - 1)
		return (NULL);
	if (ft_strlen(&s[start]) < len)
		str = (char *)malloc(sizeof(char) * (ft_strlen(&s[start]) + 1));
	else
		str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (i < len && s[start])
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
