/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 11:33:16 by ribresci          #+#    #+#             */
/*   Updated: 2026/01/15 17:57:54 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
//Libreria per va_list, va_start, va_arg, va_copy e va_end
# include <stdarg.h>

int	ft_printf(const char *s, ...);
int	ft_print_pointer(void *p);
int	ft_print_hex(unsigned long s, int x);
int	ft_putchar_fd(int c, int fd);
int	ft_putstr_fd(char *s, int fd);
int	ft_putnbr_fd_u(int n, int fd);
int	ft_putnbr_fd_di(int n, int fd);

#endif

// Program name:		libftprintf.a
// Turn in files:		Makefile, *.h, */*.h, *.c, */*.c
// Makefile:			NAME, all, clean, fclean, re
// External fnct:		malloc, free, write, va_start, va_arg, va_copy, va_end
// Libft authorized:	Yes
// Description:			Write a library that contains ft_printf(), a
// 						function that will mimic the original printf()