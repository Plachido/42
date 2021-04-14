MAP = maps/first.cub

MLX = -lmlx -lm -framework OpenGL -framework AppKit
#MLX = -I /usr/include -g -L /usr/lib -lX11 -lmlx -lXext -lm -fsanitize=address

NAME = cub3D

SRCS = 	$(shell find . -path ./src/header/minilibx -prune -false -o -name '*.c')

FILES = $(shell find . -path ./src/header/minilibx -prune -false -o -name '*.c' -o -name '*.h' ! -name 'mlx.h')

SRCS_BONUS = 

OBJSRCS = $(SRCS:.c=.o) 
OBJSRCSBONUS = $(SRCS_BONUS:.c=.o)

$(NAME) : $(OBJSRCS) $(OBJSRCSBONUS)
	@echo "[Removing last version...]"
	@rm -rf Cub3D
	@echo "[Libft compilation...]"
	@$(MAKE) bonus -C ./libft
	@echo "[Cub3D compilation...]"
	@gcc $(OBJSRCS) $(OBJSRCSBONUS) -I./src/header/cub3d.h -Wall -Wextra -Werror $(MLX) ./libft/libft.a -o $(NAME)
	@echo "[Done!]"
	@$(MAKE) clean

all : $(NAME)

run: $(MAKE) all
	./$(NAME) $(MAP)

norme:
	@norminette $(FILES)

leaks: $(MAKE) all
	leaks --atExit -- ./$(NAME) $(MAP)

clean :
	@rm -rf $(OBJSRCS) $(OBJSRCSBONUS)
	@$(MAKE) clean -C ./libft

fclean : clean
	@$(MAKE) fclean -C ./libft
	@rm -rf $(NAME)
	@rm -rf cub3d.bmp

re : fclean all

bonus : $(NAME)