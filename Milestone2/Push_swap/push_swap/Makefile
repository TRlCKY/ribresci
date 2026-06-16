# Comandi per compilare
CC = cc
# Flags per compilare
CFLAGS = -Wall -Wextra -Werror
# File sorgenti
SRC = checks.c checks2.c push_swap.c manual_sort.c manual_sort_utils.c operations.c operations2.c chunk_sort.c radix_sort.c list_utils1.c list_utils2.c split.c atoi.c printf_utils.c printf_utils1.c printf_utils2.c
# Cambia da .c in .o per il comando nel terminale
OBJ = $(SRC:.c=.o)
# Nome del programma
NAME = push_swap

# Target principale
all:	$(NAME)

# Crea e/o aggiorna la libreria statica(ar rcs) e ci associa tutti i file oggetto creati dal comando sotto
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	chmod +x $(NAME)
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
