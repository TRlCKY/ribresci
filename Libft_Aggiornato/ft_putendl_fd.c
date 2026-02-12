/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 12:01:38 by ribresci          #+#    #+#             */
/*   Updated: 2025/12/17 17:17:37 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
/*
void	ft_putendl_fd(char *s, int fd);

int	main(void)
{
	char	s[] = "42";
	int		fd;

	fd = 1;
	ft_putendl_fd(s, fd);
	return (0);
}
*/
void	ft_putendl_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}
