/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 17:06:49 by ribresci          #+#    #+#             */
/*   Updated: 2026/02/20 18:50:23 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count(void *content)
{
	int	x;
	int	n;

	x = 0;
	n = (int)content;
	while (n >= 2)
	{
		x++;
		n /= 2;
	}
	return (x + 1);
}

// Controllare free(num);
void	convert(t_list **a)
{
	long int	x;
	char		*num;
	t_list		*c;
	int			i;

	c = *a;
	while (c->next)
	{
		i = 0;
		x = c->content;
		num = malloc(sizeof(char) * (count(c->content) + 1));
		if (!num)
			return (NULL);
		while (x != 0)
		{
			num[i++] = x % 2;
			x /= 2;
		}
		c->index = num;
		free(num);
		c = c->next;
	}
}

// Controllare push e rotate(ordine parametri)
void	radix_sort(t_list **a)
{
	int		n;
	int		i;
	t_list	*c;
	t_list	*b;
	char	*s;

	n = 0;
	c = *a;
	b = ft_lstnew(NULL);
	n = ft_lstsize(c);
	i = 0;
	convert(c);
	while (c->next)
	{
		s = c->content;
		if (s[i] == 0)
			push(b, a, 1);
		else
			rotate(a, b, 0);
		c = c->next;
	}
	while (b->content)
	{
		push(b, a, 1);
		b = b->next;
	}
}
