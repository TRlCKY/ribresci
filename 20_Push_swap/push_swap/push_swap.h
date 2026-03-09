/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 11:00:22 by ribresci          #+#    #+#             */
/*   Updated: 2026/03/09 17:48:19 by ribresci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <limits.h>
# include <stdarg.h>
# include <string.h>

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}	t_list;
// Liste
t_list			*ft_lstnew(int content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstclear(t_list **lst);
void			ft_lstiter(t_list *lst, void (*f)(int));
// Printf
int				correct(const char *s);
int				check(char c, va_list *string);
int				power(int a, int b);
int				count(unsigned int n);
int				ft_print_pointer(void *p);
int				ft_print_hex(unsigned long s, int x);
int				ft_putchar_fd(int c, int fd);
int				ft_putstr_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
int				ft_putnbr_fd_u(unsigned int n, int fd);
int				ft_putnbr_fd_di(int n, int fd);
void			ft_putendl_fd(char *s, int fd);
int				ft_printf(const char *s, ...);
// Operazioni
void			swap(t_list	**a, t_list **b, int x);
void			push(t_list **a, t_list **b, int x);
void			rotate(t_list **a, t_list **b, int x);
void			reverse_rotate2(t_list **b);
void			reverse_rotate(t_list **a, t_list **b, int x);
// Sort manuale
int				find_min(t_list **a);
void			sort2(t_list **a);
void			sort3(t_list **a);
void			sort4(t_list **a);
void			sort5(t_list **a);
void			manual_sort(t_list **a);
// Radix sort
void			push_back(t_list **a, t_list **b);
int				get_number(int x);
void			radix_sort(t_list **a);
// Chunk sort
int				find_max_min(t_list **a, int max, int min);
int				find_max(t_list **b);
void			send_back(t_list **a, t_list **b);
int				get_max_min(t_list **a, int x, int min, int max);
int				find_chunk(t_list **a, int size, int chunk_size);
void			chunk_sort(t_list **a, int size, int n);
// Controlli
int				has_duplicates(t_list **a);
int				is_in_order(t_list **a);
int				ft_strlen(const char *str);
// Split
void			freeall(char **mtx);
int				count_x(char const *s, char c);
int				go(char const *s, int i, char c, int *y);
char			**ft_split(char const *s, char c);
t_list			*convert_str(char *argv);
// Atoi
int				check_limit(const char *str, int sign);
int				ft_atoi(const char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
unsigned int	ft_strlcpy(char *dest, const char *src, size_t size);
// Main
int				*order(int *b, int i);
int				*fill_array(int *b, t_list **a);
void			set_index(t_list **a, int i);
int				man_rad_chun(t_list **a, int i);
int				main(int argc, char **argv);
#endif