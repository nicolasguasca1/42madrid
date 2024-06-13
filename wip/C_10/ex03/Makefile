CC=gcc
CFLAGS=-Wall -Wextra -pedantic -std=c99
LDFLAGS=

# Lista de archivos fuente
SOURCES=main.c hex_functions.c

# Objetos generados
OBJECTS=$(SOURCES:.c=.o)

# Nombre del ejecutable
EXECUTABLE=ft_hexdump

all:	$(EXECUTABLE)

$(EXECUTABLE):	$(OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@

%.o:	%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean:	clean
	rm -f $(EXECUTABLE)

re:	fclean all

.PHONY:	all clean fclean re

