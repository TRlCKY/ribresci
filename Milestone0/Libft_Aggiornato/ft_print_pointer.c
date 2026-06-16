/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:24:58 by ribresci          #+#    #+#             */
/*   Updated: 2026/01/16 12:10:20 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"
/*
int	print_pointer(void *p);

int	main(void){
	int	a;

	a = 0;
	print_pointer(&a);
	return (0);
}
*/
int	ft_print_pointer(void *p)
{
	int				i;
	unsigned long	s;

	i = 0;
	s = (unsigned long)p;
	if (!s)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	i += ft_putstr_fd("0x", 1);
	i += ft_print_hex(s, 0);
	return (i);
}
