/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   get_next_line.c									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: ribresci <ribresci@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2026/01/19 16:20:32 by ribresci		  #+#	#+#			 */
/*   Updated: 2026/02/02 16:48:26 by ribresci		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

char	*copy_stash(char *stash, char *line);
char	*create_line(char *stash);
char	*read_buff(int fd, char *stash, int *y);
int		last_check(char *string, char *stash);
char	*get_next_line(int fd);

// int	main(void)
// {
// 	int		fd;
// 	char	*s;

// 	fd = open("bob.txt", O_RDONLY);
// 	s = get_next_line(fd);
// 	printf("\n%s", s);
// 	free(s);
// 	s = get_next_line(fd);
// 	printf("\n%s", s);
// 	free(s);
// 	s = get_next_line(fd);
// 	printf("\n%s", s);
// 	free(s);
// 	s = get_next_line(fd);
// 	printf("\n%s", s);
// 	free(s);
// 	s = get_next_line(fd);
// 	printf("\n%s", s);
// 	free(s);
// 	s = get_next_line(fd);
// 	printf("\n%s", s);
// 	free(s);
// 	s = get_next_line(fd);
// 	printf("\n%s", s);
// 	free(s);
// 	s = get_next_line(fd);
// 	printf("\n%s", s);
// 	free(s);
// 	s = get_next_line(fd);
// 	printf("\n%s", s);
// 	free(s);
// 	s = get_next_line(fd);
// 	printf("\n%s", s);
// 	free(s);
// 	s = get_next_line(fd);
// 	printf("\n%s", s);
// 	free(s);
// 	s = get_next_line(fd);
// 	printf("\n%s", s);
// 	free(s);
// 	s = get_next_line(fd);
// 	printf("\n%s", s);
// 	free(s);
// 	s = get_next_line(fd);
// 	printf("\n%s", s);
// 	free(s);
// 	return (0);
// }

char	*copy_stash(char *stash, char *line)
{
	size_t	i;

	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = '\n';
		line[i + 1] = '\0';
		if (stash[i + 1])
			gnl_memmove(stash, &stash[i + 1], gnl_strlen(&stash[i + 1]) + 1);
		else
			stash[0] = '\0';
	}
	else
	{
		stash[0] = '\0';
		line[i] = '\0';
	}
	return (line);
}

char	*create_line(char *stash)
{
	char	*line;
	size_t	e;

	e = 0;
	while (stash[e] != '\n' && stash[e])
		e++;
	line = malloc (sizeof(char) * (e + 2));
	if (!line)
		return (NULL);
	line[0] = '\0';
	line = copy_stash(stash, line);
	return (line);
}

char	*read_buff(int fd, char *stash, int *y)
{
	char		*buf;
	ssize_t		x;
	char		*tmp;

	x = 1;
	while (x && !gnl_strchr(stash, '\n'))
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf)
			return (free(buf), NULL);
		x = read(fd, buf, BUFFER_SIZE);
		if (x < 0)
			return (free(buf), NULL);
		buf[x] = 0;
		if (x == 0)
			*y = 1;
		tmp = gnl_strjoin(stash, buf);
		if (!tmp)
			return (free(buf), NULL);
		stash = tmp;
		free(buf);
	}
	return (stash);
}

int	last_check(char *string, char *stash)
{
	if (string[0] == '\0')
	{
		free(string);
		if (stash[0] == '\0')
			return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*string;
	int			y;
	char		*tmp;

	y = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
	{
		stash = malloc(1);
		if (!stash)
			return (free(stash), NULL);
		stash[0] = '\0';
	}
	tmp = read_buff(fd, stash, &y);
	if (!tmp)
		return (free(stash), stash = NULL, NULL);
	stash = tmp;
	string = create_line(stash);
	if (!string)
		return (free(stash), stash = NULL, NULL);
	if (last_check(string, stash))
		return (free(stash), stash = NULL, NULL);
	return (string);
}
