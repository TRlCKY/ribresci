/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 15:20:06 by ribresci          #+#    #+#             */
/*   Updated: 2025/12/17 17:22:34 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
/*
#include <stdio.h>

void	del(void *lst);
void	ft_lstdelone(t_list *lst, void (*del)(void *));

int	main(void)
{
	t_list	*lst = ft_lstnew("Ciao");
	t_list	*new = ft_lstnew("Ciaoooo");

	ft_lstadd_back(&lst, new);
	ft_lstdelone(new, del);
	printf("%s\n", (char *)lst->content);
	if (!(lst->next))
		printf("Huh?\n");
	return (0);
}

void	del(void *lst)
{
	free(lst);
}
*/
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	t_list	*ptr;

	if (!lst || !del)
		return ;
	ptr = lst;
	del(ptr->content);
	free(ptr);
}
