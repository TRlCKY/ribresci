/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:23:05 by ribresci          #+#    #+#             */
/*   Updated: 2025/12/17 17:06:51 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
/*
char	*ft_strchr(char *str, char c);

int main(){
	char str[] = "ciao, mi chiamo Riccardo";
	char to_find[] = "mi";
	char *ptr;
	ptr=ft_strchr(str, to_find);
	printf("%s\n", ptr);
	char str1[] = "ciao, mi chiamo Riccardo";
	char to_find1[] = "z";
	ptr=ft_strchr(str1, to_find1);
	printf("%s\n", ptr);
	return 0;
}
*/
char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (str);
	if (c > 126)
		return (str);
	if (c == 0)
	{
		while (str[i])
			i++;
		return (&(str[i]));
	}
	while (str[i])
	{
		if (str[i] == c)
			return (&(str[i]));
		i++;
	}
	return (NULL);
}
