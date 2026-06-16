/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:23:05 by ribresci          #+#    #+#             */
/*   Updated: 2025/12/17 17:07:22 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
/*
int	ft_strncmp(char *s1, char *s2, size_t n);

int main(){
	char s1[]="ciao";
	char s2[]="ciao";
	int x=0;
	x=ft_strncmp(s1, s2, 0);
	printf("%d\n", x);
	s1[0]='C';
	x=ft_strncmp(s1, s2, 3);
	printf("%d\n", x);
	s1[0]='c';
	s2[0]='C';
	x=ft_strncmp(s1, s2, 2);
	printf("%d\n", x);
	s2[0] = 'c';
	s2[4] = 'a';
	x=ft_strncmp(s1, s2, 4);
	printf("%d\n", x);
	s1[4] = 'x';
	s2[4] = '\0';
	x=ft_strncmp(s1, s2, 4);
	printf("%d\n", x);
	return 0;
}
*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (i == n)
		return (0);
	return (s1[i] - s2[i]);
}
