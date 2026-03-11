/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:16:04 by ribresci          #+#    #+#             */
/*   Updated: 2026/03/11 18:52:50 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Controlla che tutti gli argomenti siano diversi
// Restituisce 0 se non lo sono, 1 se lo sono
int	has_duplicates(t_list **a)
{
	t_list	*b;
	t_list	*c;

	b = *a;
	while (b)
	{
		c = b->next;
		while (c)
		{
			if (b->content == c->content)
				return (1);
			c = c->next;
		}
		b = b->next;
	}
	return (0);
}

int	check_arg(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (!s[i])
		return (error());
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (error());
		i++;
	}
	return (1);
}

// Controlla che tutti gli elementi siano validi (no caratteri diversi da
// numeri, solo un + o -...)
int	is_valid(char **argv, int argc)
{
	int		i;
	char	**str;

	if (argc == 2)
	{
		if (!argv[1][0])
			return (error());
		str = ft_split(argv[1], ' ');
		if (!str || !str[0])
			return (freeall(str), error());
		i = -1;
		while (str[++i])
			if (!check_arg(str[i]))
				return (freeall(str), 0);
		return (freeall(str), 1);
	}
	i = 1;
	while (argv[i])
	{
		if (!check_arg(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

// Controlla che gli elementi siano gia' in ordine
// Restituisce 0 se non lo sono, 1 se lo sono
int	is_in_order(t_list **a)
{
	t_list	*b;
	t_list	*c;

	if (!a || !*a)
		return (1);
	b = *a;
	c = b->next;
	while (c)
	{
		if (b->index > c->index)
			return (0);
		b = b->next;
		c = c->next;
	}
	return (1);
}

// Controlla che i numeri siano gli stessi a quelli della lista
int	check_list(t_list **a, char **argv)
{
	return (0);
}
