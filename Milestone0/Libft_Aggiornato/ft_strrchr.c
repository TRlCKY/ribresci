/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:23:05 by ribresci          #+#    #+#             */
/*   Updated: 2025/12/18 18:35:27 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
/*
char	*ft_strrchr(char *str, char c);

int main(){
	char str[] = "ciao, mi chiamo Riccardo";
	char to_find = 'm';
	char *ptr;
	ptr=ft_strrchr(str, to_find);
	printf("%s\n", ptr);
	char str1[] = "ciao, mi chiamo Riccardo";
	char to_find1 = "'z';
	ptr=ft_strrchr(str1, to_find1);
	printf("%s\n", ptr);
	return 0;
}
*/
char	*ft_strrchr(char *str, int c)
{
	int		i;
	char	*s;

	i = 0;
	s = NULL;
	if (!str)
		return (NULL);
	if (c == 0)
	{
		while (str[i])
			i++;
		return (&(str[i]));
	}
	if (!str)
		return (str);
	while (str[i])
	{
		if (str[i] == (char )c)
			s = &(str[i]);
		i++;
	}
	return (s);
}
