/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 19:02:01 by ribresci          #+#    #+#             */
/*   Updated: 2026/01/17 15:04:27 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include "ft_printf.h"
// #include <stdio.h>

// int	correct(const char *s);
// int	check(char c, va_list *string);
// int	ft_printf(const char *s, ...);

// int	main(void)
// {
// 	int				a;
// 	char			b;
// 	char			*c;
// 	unsigned int	d;

// 	a = 123;
// 	b = 'i';
// 	c = "animal";
// 	d = 123456789;
// 	ft_printf("Ciao, %d %s%c hanno ucciso\t%i persone\nGG\n", a, c, b, d);
// 	ft_printf("%%%");
// 	ft_printf("%u in esadecmale:\t%x\to %X\n Indirizzo: %p\n\n", d, d, d, &d);
// 	printf("Ciao, %d %s%c hanno ucciso\t%i persone\nGG\n", a, c, b, d);
// 	printf("%%%");
// 	printf("%u in esadecmale:\t%x\to %X\n Indirizzo: %p\n", d, d, d, &d);
// }

int	correct(const char *s)
{
	int	i;

	i = 0;
	while (s[i + 3])
	{
		if ((s[i] == '%' && s[i + 1] == '%' && s[i + 2] == '%'
				&& s[i + 3] != '%' && s[i + 3] != 'c' && s[i + 3] != 's'
				&& s[i + 3] != 'p' && s[i + 3] != 'd' && s[i + 3] != 'i'
				&& s[i + 3] != 'u' && s[i + 3] != 'x' && s[i + 3] != 'X'
				&& s[i + 3] != ' ')
			&& (s[i + 4] && s[i + 4] != '%' && s[i + 4] != 'c'
				&& s[i + 4] != 's' && s[i + 4] != 'p' && s[i + 4] != 'd'
				&& s[i + 4] != 'i' && s[i + 4] != 'u' && s[i + 4] != 'x'
				&& s[i + 4] != 'X'))
			return (1);
		i++;
	}
	return (0);
}

int	check(char c, va_list *string)
{
	if (c == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	if (c == 'c')
		return (ft_putchar_fd(va_arg(*string, int), 1));
	if (c == 's')
		return (ft_putstr_fd(va_arg(*string, char *), 1));
	if (c == 'p')
		return (ft_print_pointer(va_arg(*string, void *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr_fd_di(va_arg(*string, int), 1));
	if (c == 'u')
		return (ft_putnbr_fd_u(va_arg(*string, unsigned int), 1));
	if (c == 'x')
		return (ft_print_hex(va_arg(*string, unsigned int), 0));
	if (c == 'X')
		return (ft_print_hex(va_arg(*string, unsigned int), 1));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		x;
	va_list	string;

	va_start(string, s);
	i = 0;
	x = 0;
	if (correct(s))
		return (-1);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
			x += check(s[++i], &string);
		else
		{
			write(1, &s[i], 1);
			x++;
		}
		i++;
	}
	va_end(string);
	return (x);
}

// va_list ciao;		INIZIALIZZA LA LISTA DI ARG. VARIABILI
// va_start(ciao, bob);	DICHIARA ciao CON bob PRIMO ELEMENTO
// va_arg(ciao, int);	RESTITUISCE IL PARAMETRO DI ciao CON IL 
// 						TIPO int
// 						(SE ERA UN PUNTATORE va_args(ciao, *int))
// 						SPOSTA ANCHE AVANTI IL PUNTATORE
// va_copy(ciao, bob);	COPIA LO STATO CORRENTE DELLA LISTA IN UNA
// 						ALTRA VARIABILE
// va_end(ciao);		FINALIZZA ciao E NON PUO' ESSERE UTILIZZATA
// 						DI NUOVO. AD OGNI va_start CORRISPONDE UN
// 						va_end

// %c:	single character.
// %s:	string (as defined by the common C convention).
// %p:	The void * pointer argument has to be printed in hexadecimal format.
// %d:	decimal (base 10) number.
// %i:	an integer in base 10.
// %u:	an unsigned decimal (base 10) number.
// %x:	number in hexadecimal (base 16) lowercase format.
// %X:	number in hexadecimal (base 16) uppercase format.
// %%:	percent sign