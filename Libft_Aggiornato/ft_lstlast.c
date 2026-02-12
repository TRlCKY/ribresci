/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 13:00:58 by ribresci          #+#    #+#             */
/*   Updated: 2025/12/18 18:32:24 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <stdio.h>

t_list	*ft_lstlast(t_list *lst);

int	main(void)
{
	t_list	*lst = ft_lstnew("Come");
	t_list	*new = ft_lstnew("Va?");

	ft_lstadd_back(&lst, new);
	lst = ft_lstlast(lst);
}
*/
t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
