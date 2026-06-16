/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:23:32 by ribresci          #+#    #+#             */
/*   Updated: 2026/02/02 18:32:31 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <unistd.h>
# include <stdlib.h>

// utils functions
size_t	gnl_strlen(const char *str);
void	gnl_strlcpy(char *dest, const char *src, size_t size);
char	*gnl_strjoin(char *s1, char *s2);
char	*gnl_strchr(char *str, int c);
void	*gnl_memmove(void *dest, const void *src, size_t n);
// get_next_line functions
char	*copy_stash(char *stash, char *line);
char	*create_line(char *stash);
char	*read_buff(int fd, char *stash, int *y);
int		last_check(char *string, char *stash);
char	*get_next_line(int fd);

#endif