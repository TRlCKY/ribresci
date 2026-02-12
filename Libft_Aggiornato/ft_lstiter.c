/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:19:45 by ribresci          #+#    #+#             */
/*   Updated: 2025/12/17 17:24:40 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <stdio.h>

void	f(void *lst);
void	ft_lstiter(t_list *lst, void (*f)(void *));

int	main(void)
{
	t_list	*lst = ft_lstnew("Ciao");
	t_list	*new = ft_lstnew("Come");
	t_list	*new1 = ft_lstnew("Va");
	t_list	*new2 = ft_lstnew("?");

	ft_lstadd_back(&lst, new);
	ft_lstadd_back(&lst, new1);
	ft_lstadd_back(&lst, new2);
	ft_lstiter(lst, f);
	return (0);
}

void	f(void *lst)
{
	if (lst)
		printf("Ciao\n");
	else
		printf("Addio\n");
}
*/
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
