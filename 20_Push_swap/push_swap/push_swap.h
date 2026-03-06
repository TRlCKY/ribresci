/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribresci <ribresci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 11:00:22 by ribresci          #+#    #+#             */
/*   Updated: 2026/03/06 17:11:14 by ribresci         ###   ########.fr       */
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
	void			*content;
	int				*index;
	struct s_list	*next;
}	t_list;
// Liste
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
// Printf
int				ft_printf(const char *s, ...);
int				ft_print_pointer(void *p);
int				ft_print_hex(unsigned long s, int x);
int				ft_putchar_fd(int c, int fd);
int				ft_putstr_fd(char *s, int fd);
int				ft_putnbr_fd_u(int n, int fd);
int				ft_putnbr_fd_di(int n, int fd);
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
int				count_pos(t_list **a, int x);
void			rotate_reverse(t_list **a, t_list **b, int *i);
void			send_back(t_list **a, t_list **b);
void			chunk_sort(t_list **a, int size);
// Controlli
int				has_duplicates(t_list **a);
int				is_in_order(t_list **a);
int				ft_strlen(const char *str);
void			check_limit(const char *str, int *x);
char			*ft_atoi(const char *str);
t_list			*convert_str(char **argv);
// Main
unsigned char	*order(unsigned char **b, int i);
unsigned char	*fill_array(unsigned char **b, t_list **a);
void			*index(t_list *a, int i);
int				man_rad_chun(t_list **a, int i);
int				main(int argc, char **argv);
#endif