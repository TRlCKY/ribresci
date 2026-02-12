/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:47:13 by ribresci          #+#    #+#             */
/*   Updated: 2025/12/18 16:53:14 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <stdio.h>

void	ft_lstadd_front(t_list **lst, t_list *new);

int	main(void)
{
	t_list	*lst = ft_lstnew("Ciao");
	t_list	*new = ft_lstnew("Ciaoooo");

	ft_lstadd_front(&lst, new);
	printf("%s\n", (char *)new->content);
	new = new->next;
	printf("%s\n", (char *)new->content);
	return (0);
}
*/
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new && lst)
	{
		new->next = *lst;
		*lst = new;
	}
}
