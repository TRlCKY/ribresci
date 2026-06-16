/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:32:43 by ribresci          #+#    #+#             */
/*   Updated: 2025/12/18 18:26:10 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <stdio.h>

void	f(unsigned int n, char *s);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

int	main(void)
{
	char	s[] = "Ciao Ciao";

	ft_striteri(s, f);
	printf("%s\n", s);
	return (0);
}

void	f(unsigned int n, char *s)
{
	if (n % 2 == 0)
		*s = ft_tolower(*s);
	else
		*s = ft_toupper(*s);
}
*/
void	ft_striteri(char *s, void (*f)(unsigned int n, char *s))
{
	unsigned int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
