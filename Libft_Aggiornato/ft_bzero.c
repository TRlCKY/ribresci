/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:23:05 by ribresci          #+#    #+#             */
/*   Updated: 2025/12/18 17:18:27 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
/*
void	ft_bzero(void *s, size_t n);

int	main()
{
	char	s[] = "ciaoooo";
	size_t	n;

	n = 5;
	ft_bzero(s, n);
	printf("%s\n", s);
	return (0);
}
*/
void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	i = 0;
	str = s;
	while (i < n)
	{
		*str = 0;
		str++;
		i++;
	}
}
