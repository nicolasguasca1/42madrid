NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = srcs
INC_DIR = includes
OBJ_DIR = srcs

SRCS = $(addprefix $(SRC_DIR)/, ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c)
OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))
INC = $(INC_DIR)/ft.h

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "Libft compiled successfully"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled $<"

clean:
	@rm -rf $(OBJ_DIR)/*.o
	@echo "Cleaned up object files"

fclean: clean
	@rm -f $(NAME) $(OBJS)
	@echo "Cleaned up library file"

re: fclean all

.PHONY: all clean fclean re

