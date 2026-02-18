/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 10:14:44 by ribresci          #+#    #+#             */
/*   Updated: 2026/02/18 18:15:56 by ribresci         ###   ########.fr       */
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

int	check_content(char *argv)
{
	
}

int	main(int argc, char *argv)
{
	t_list	*a;

	if (argc < 2 || check_same(argv) || check_content(argv))
		return ;
	a = ft_lstnew(argv[++argc]);
	while (argv[++argc])
	{
		if (argv[argc])
			ft_lstadd_back(a, argv[argc]);
	}
}
