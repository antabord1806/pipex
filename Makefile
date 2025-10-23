NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f

LIB_DIR = libft

INCLUDES = -I $(LIB_DIR)

SRC = argument_parsing.c pipex.c single_town.c \

OBJ = $(SRC: .c=.o)

LIBFT = $(LIB_DIR)/libft.a

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIB_DIR)

all:
	$(NAME)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIB_DIR) clean

fclean:
	rm -f $(NAME)
	$(MAKE) -C $(LIB_DIR) fclean

re:
	fclean all

.PHONY: all fclean clean re