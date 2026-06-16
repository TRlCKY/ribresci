/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 15:02:03 by ribresci          #+#    #+#             */
/*   Updated: 2025/12/17 17:21:52 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <stdio.h>

void	ft_lstadd_back(t_list **lst, t_list *new);

int	main(void)
{
	t_list	*lst = ft_lstnew("Ciao");
	t_list	*new = ft_lstnew("Ciaoooo");

	ft_lstadd_back(&lst, new);
	printf("%s\n", (char *)lst->content);
	lst = lst->next;
	printf("%s\n", (char *)lst->content);
	return (0);
}
*/
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	ptr = *lst;
	if (!*lst && new)
	{
		*lst = new;
		return ;
	}
	if (!*lst || !new)
		return ;
	ptr = ft_lstlast(ptr);
	(ptr)->next = new;
}
