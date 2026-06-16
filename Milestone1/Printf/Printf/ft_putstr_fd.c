/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 09:53:04 by ribresci          #+#    #+#             */
/*   Updated: 2026/01/16 14:03:09 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
/*
int	ft_putstr_fd(char *s, int fd);

int	main(void)
{
	char	s[] = "42";
	int		fd;

	fd = 1;
	ft_putstr_fd(s, fd);
	return (0);
}
*/
int	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		write(fd, &(s[i]), 1);
		i++;
	}
	return (i);
}
