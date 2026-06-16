/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 13:11:19 by ribresci          #+#    #+#             */
/*   Updated: 2026/02/02 17:08:09 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

size_t	gnl_strlen(const char *str);
void	gnl_strlcpy(char *dest, const char *src, size_t size);
char	*gnl_strjoin(char *s1, char *s2);
char	*gnl_strchr(char *str, int c);
void	*gnl_memmove(void *dest, const void *src, size_t n);

size_t	gnl_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (str)
	{
		while (str[i])
			i++;
	}
	return (i);
}

void	gnl_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	e;

	i = 0;
	e = 0;
	while (src[e])
		e++;
	if (size > 0)
	{
		while (src[i] && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*s3;
	size_t	i;
	size_t	e;

	i = 0;
	e = 0;
	if (s1)
		i = gnl_strlen(s1);
	if (s2)
		e = gnl_strlen(s2);
	s3 = (char *)malloc(sizeof(char) * (i + e + 1));
	if (!s3)
		return (NULL);
	if (s1)
		gnl_strlcpy(s3, s1, i + 1);
	else
		s3[0] = '\0';
	if (s2)
		gnl_strlcpy(&s3[i], s2, e + 1);
	s3[i + e] = '\0';
	if (s1)
		free(s1);
	return (s3);
}

char	*gnl_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (str);
	if (c > 126)
		return (str);
	if (c == 0)
	{
		while (str[i])
			i++;
		return (&(str[i]));
	}
	while (str[i])
	{
		if (str[i] == c)
			return (&(str[i]));
		i++;
	}
	return (NULL);
}

void	*gnl_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;
	size_t				i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	s = (unsigned const char *)src;
	d = (unsigned char *)dest;
	if (&d[i] < &s[i])
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
		while (n--)
			d[n] = s[n];
	return (d);
}
