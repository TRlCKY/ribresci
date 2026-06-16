/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:28:58 by ribresci          #+#    #+#             */
/*   Updated: 2026/01/16 12:15:46 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"
/*
int	print_hex(unsigned long s, int x);

int	main(void){
	unsigned long	s;
	int				x;

	x = 0;
	s = "a0f780";
	print_hex(s, x);
	return (0);
}
*/
int	ft_print_hex(unsigned long s, int x)
{
	char	*bob;
	int		n;

	if (x == 0)
		bob = "0123456789abcdef";
	else
		bob = "0123456789ABCDEF";
	n = 0;
	if (s >= 16)
		n += ft_print_hex((s / 16), x);
	n += ft_putchar_fd(bob[s % 16], 1);
	return (n++);
}
