/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 11:53:59 by ribresci          #+#    #+#             */
/*   Updated: 2025/12/18 15:46:50 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
/*
#include <stdio.h>

char	f(unsigned int n, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

int	main(void)
{
	char const		*s = "Ciao ciao";
	char			*d;

	d = ft_strmapi(s, f);
	printf("%s\n", d);
	return (0);
}

char	f(unsigned int n, char c)
{
	if (n % 2 == 0)
		return (ft_toupper(c));
	else
		return (ft_tolower(c));
}
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	e;
	char			*d;

	i = 0;
	e = ft_strlen((char *)s);
	d = malloc((e + 1) * sizeof(char));
	if (!d)
		return (NULL);
	while (s[i])
	{
		d[i] = f(i, s[i]);
		i++;
	}
	d[i] = '\0';
	return (d);
}
