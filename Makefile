
NAME = pipex

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

LIBFT_DIR = libft

INCLUDES = -I$(INC_DIR) -I$(LIBFT_DIR)

SRC = argument_parsing.c pipex.c single_town.c utils.c pipe_city.c here_doc_handler.c \

OBJ = $(SRC:.c=.o)

LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re