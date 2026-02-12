# Comandi per compilare
CC = cc
# Flags per compilare
CFLAGS = -Wall -Wextra -Werror
# File sorgenti
SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memcmp.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstsize.c ft_lstlast.c ft_lstiter.c ft_lstmap.c ft_lstdelone.c ft_lstadd_front.c ft_lstadd_back.c ft_lstclear.c ft_printf.c ft_print_hex.c ft_print_pointer.c ft_putchar_fd.c ft_putnbr_fd_di.c ft_putnbr_fd_u.c ft_putstr_fd.c get_next_line.c get_next_line.c get_next_line_utils.c
# Cambia da .c in .o per il comando nel terminale
OBJ = $(SRC:.c=.o)
# Nome del programma
NAME = libft.a

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
