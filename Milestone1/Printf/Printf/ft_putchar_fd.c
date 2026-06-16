/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 09:49:52 by ribresci          #+#    #+#             */
/*   Updated: 2026/01/15 17:57:28 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
/*
int	ft_putchar_fd(char c, int fd);

int	main()
{
	char	c;
	int		fd;

	fd = 1;
	c = 'a';
	ft_putchar_fd(c, fd);
	return (0);
}
*/
int	ft_putchar_fd(int c, int fd)
{
	write(fd, &c, 1);
	return (1);
}
