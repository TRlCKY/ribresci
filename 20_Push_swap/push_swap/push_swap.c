/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 10:14:44 by ribresci          #+#    #+#             */
/*   Updated: 2026/02/24 12:37:24 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_same(char *argv)
{
	int	i;
	int	e;

	i = 1;
	e = 1;
	while (argv[i])
	{
		while (argv[e])
		{
			if (argv[i] != argv[e] && i != e)
				e++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}

void	order(t_list **a, unsigned char **b, int i)
{
	int				e;
	int				k;
	unsigned char	d;

	k = 0;
	e = 0;
	while (e < i)
	{
		while (k < i - 1)
		{
			if (b[k] > b[k + 1])
			{
				d = b[k];
				b[k] = b[k + 1];
				b[k + 1] = d;
			}
			k++;
		}
		e++;
	}
}

void	fill_array(unsigned char **b, t_list **a)
{
	int		e;
	t_list	*c;
	int		i;

	i = ft_lstsize(*a);
	c = *a;
	e = 0;
	while (c->next)
	{
		b[e++] = c->content;
		c = c->next;
	}
	order(a, b, i);
}

void	index(t_list **a, int i)
{
	unsigned char	*b;
	t_list			*c;
	unsigned int	e;

	b = malloc(sizeof(unsigned char) * i + 1);
	if (!b)
		return (NULL);
	fill_array(b, a);
	c = *a;
	while (c->next)
	{
		e = 0;
		while (e < i)
		{
			if (b[e] == c->content)
				c->index = e++;
		}
		c = c->next;
	}
	free(b);
}

int	main(int argc, char *argv)
{
	t_list	*a;
	int		i;

	if (argc < 2 || check_same(argv) || check_content(argv))
		return ;
	a = ft_lstnew(argv[++argc]);
	while (argv[++argc])
		ft_lstadd_back(a, argv[argc]);
	i = ft_lstsize(a);
	index(a, i);
	if (i >= 2 && i < 5)
		manual_sort(a);
	if (i >= 5 && i < 100)
		radix_sort(a);
	if (i >= 100)
		chunk_sort(a);
}
