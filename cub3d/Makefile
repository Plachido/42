NAME = cub3D

MAP = maps/first.cub

LIBFT = ./libft.a
MLX = libmlx.dylib
FLAGS = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit

SRCS = 	$(shell find . -path ./src/header/minilibx_mms_20200219 -prune -false -o -name '*.c')
FILES = $(shell find . -path ./src/header/minilibx_mms_20200219 -prune -false -o -name '*.c' -o -name '*.h' ! -name 'mlx.h')

CC	=	gcc

OBJ = $(SRCS:.c=.o)

$(NAME): $(OBJ) $(MLX) $(LIBFT)
	@echo "[Removing last version...]"
	@rm -rf Cub3D
	@echo "[Cub3D compilation...]"
	@$(MAKE) bonus -C ./libft
	@gcc $(SRCS) $(FLAGS) -fsanitize=address $(MLX) $(LIBFT) -o $(NAME) -g
	@echo "[Done!]"
	@$(MAKE) clean

$(LIBFT):
	@echo "[compiling libft...]"
	@$(MAKE) bonus -C ./libft
	@$(MAKE) clean -C ./libft
	@mv libft/libft.a .

$(MLX):
	@echo "[compiling mlx...]"
	@$(MAKE) -C src/header/minilibx_mms_20200219
	@mv src/header/minilibx_mms_20200219/libmlx.dylib .

all : $(NAME)

norme:
	@norminette $(FILES)

leaks: $(MAKE) all
	@leaks --atExit -- ./$(NAME) $(MAP)

run: $(MAKE) re
	./$(NAME) $(MAP)

clean:
	@rm -rf $(OBJ)
	@$(MAKE) clean -C ./libft

fclean: clean
	@rm -rf $(NAME) $(LIBFT) $(MLX)
	@$(MAKE) fclean -C ./libft

re : fclean all