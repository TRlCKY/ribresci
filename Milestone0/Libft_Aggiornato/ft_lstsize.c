/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 12:46:57 by ribresci          #+#    #+#             */
/*   Updated: 2025/12/17 17:20:57 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <stdio.h>

int	ft_lstsize(t_list *lst);

int	main(void)
{
	t_list	*lst = ft_lstnew("1");
	t_list	*new = ft_lstnew("0");

	ft_lstadd_front(&lst, new);
	printf("Size: %d\n", ft_lstsize(new));
	return (0);
}
*/
int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*ptr;

	i = 0;
	ptr = lst;
	while (ptr)
	{
		ptr = ptr->next;
		i++;
	}
	return (i);
}
