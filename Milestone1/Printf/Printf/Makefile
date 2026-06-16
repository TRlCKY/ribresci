# Comandi per compilare
CC = cc
# Flags per compilare
CFLAGS = -Wall -Wextra -Werror
# File sorgenti
SRC = ft_printf.c ft_print_hex.c ft_print_pointer.c ft_putstr_fd.c ft_putchar_fd.c ft_putnbr_fd_u.c ft_putnbr_fd_di.c
# Cambia da .c in .o per il comando nel terminale
OBJ = $(SRC:.c=.o)
# Nome del programma
NAME = libftprintf.a

# Target principale
all:	$(NAME)

# Crea e/o aggiorna la libreria statica(ar rcs) e ci associa tutti i file oggetto creati dal comando sotto
$(NAME): $(OBJ)
		ar rcs $(NAME) $(OBJ)
# Prende tutti i file .c($<), li compila in file oggetto(-o) e gli rimette lo stesso nome($@)
%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@
# Elimina tutti i file oggetto
clean:
		rm -f $(OBJ)
# Elimina tutti i file oggetto e la libreria statica
fclean: clean
		rm -f $(NAME)
# Elimina tutti i file oggetto e la libreria statica e poi ricrea tutto
re: fclean all

.PHONY: all clean fclean re