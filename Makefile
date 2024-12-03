NAME = so_long

SRC = src/so_long.c \
    get_next_line/get_next_line.c\
 	get_next_line/get_next_line_utils.c\
  	src/valid.c\
   	src/game.c\
    src/validpath.c\
	src/free.c\
	src/operation.c\
	src/utils.c

OBJ := $(SRC:%.c=%.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
INCLUDES = -Ilibft -Ift_printf -I./MinilibX
MLX = -L./MinilibX -lmlx -lXext -lX11 -lm

all: $(NAME)

libft/libft.a:
	@make -C libft

ft_printf/libftprintf.a:
	@make -C ft_printf

$(NAME): $(OBJ) libft/libft.a ft_printf/libftprintf.a
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -Llibft -lft -Lft_printf -lftprintf $(MLX)

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(RM) $(OBJ)
	@make clean -C libft
	@make clean -C ft_printf

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C libft
	@make fclean -C ft_printf

re: fclean all

.PHONY: all clean fclean re libft ft_printf