/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 18:04:31 by ribresci          #+#    #+#             */
/*   Updated: 2025/12/18 18:19:55 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
/*
#include <stdio.h>

void	*f(void *lst);
void	del(void *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

int	main(void)
{
	t_list	*lst = ft_lstnew("Ciao");
	t_list	*new = ft_lstnew("Come");
	t_list	*new1 = ft_lstnew("Va");
	t_list	*new2 = ft_lstnew("?");
	t_list	*final;

	ft_lstadd_back(&lst, new);
	ft_lstadd_back(&lst, new1);
	ft_lstadd_back(&lst, new2);
	final = ft_lstmap(lst, &f, del);
	while (final)
	{
		printf("%s\n", (char *)final->content);
		final = final->next;
	}
	return (0);
}

void	*f(void *lst)
{
	printf("%p", lst);
	return (lst);
}

void	del(void *lst)
{
	free(lst);
}
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*final;
	t_list	*ptr;

	if (!lst || !f || !del)
		return (NULL);
	final = ft_lstnew(f(lst->content));
	if (!final)
	{
		ft_lstclear(&final, del);
		return (NULL);
	}
	while (lst->next)
	{
		lst = lst->next;
		ptr = ft_lstnew(f(lst->content));
		if (!ptr)
		{
			ft_lstclear(&final, del);
			return (NULL);
		}
		ft_lstadd_back(&final, ptr);
	}
	return (final);
}
