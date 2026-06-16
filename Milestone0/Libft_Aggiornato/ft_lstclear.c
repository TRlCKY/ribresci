/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:03:41 by ribresci          #+#    #+#             */
/*   Updated: 2025/12/17 17:25:23 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
/*
#include <stdio.h>

void	del(void *lst);
void	ft_lstclear(t_list **lst, void (*del)(void *));

int	main(void)
{
	t_list	*lst = ft_lstnew("Ciao");
	t_list	*new = ft_lstnew("Come");
	t_list	*new1 = ft_lstnew("Va");
	t_list	*new2 = ft_lstnew("?");

	ft_lstadd_back(&lst, new);
	ft_lstadd_back(&lst, new1);
	ft_lstadd_back(&lst, new2);
	printf("8\n");
	while (lst->next)
	{
		printf("%s\n", (char *)lst->content);
		lst = lst->next;
	}
	return (0);
}

void	del(void *lst)
{
	free(lst);
}
*/
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;

	if (!(*lst))
		return ;
	ptr = *lst;
	while (ptr)
	{
		del((*lst)->content);
		ptr = (*lst)->next;
		free(*lst);
		*lst = ptr;
	}
	*lst = NULL;
}
