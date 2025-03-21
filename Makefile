NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLX_FLAGS = -L/usr/lib/X11 -lXext -lX11
LIBFT_PATH = includes/my_libft
MLX_PATH = includes/mlx
LIBFT = $(LIBFT_PATH)/libft.a
MLX = $(MLX_PATH)/libmlx.a

CONTAINER_WORKDIR_PATH = "/Users/lraggio/Studies/my_container/"
BAD_MAPS = ${shell find ./maps/bad}

# Colors
RESET=\033[0m
PURPLE=\033[35m
GREEN=\033[32m
PINK=\033[35m
RED=\033[31m
BLUE=\033[34m

#MAP = maps/good/test_map.cub # TA DANDO RUIM NESSE!
MAP = maps/good/big.cub
#MAP = maps/good/matrix.cub
#MAP = maps/good/test_pos_bottom.cub;
#MAP = maps/good/test_textures.cub
#MAP = maps/good/subject_map.cub
#MAP = maps/bad/empty.cub
#MAP = maps/bad/no_filetype
#MAP = maps/bad/map_starts_with_W_in_middle_of_map.cub

SRCS = \
srcs/main.c \
srcs/map/map.c \
srcs/utils/clear.c \
srcs/map/get_map_data.c \
srcs/map/map_validation.c \
srcs/map/rgb.c \
srcs/map/walls.c \
srcs/map/ceiling_and_floor.c \
srcs/map/is_map.c \
srcs/map/char_validation.c \
srcs/map/line_is.c \
srcs/map/floodfill.c \
srcs/map/texture.c \
srcs/map/color.c \
srcs/map/copy_map.c \
srcs/player/keys.c \
srcs/player/moves.c \
srcs/player/rotate.c \
srcs/player/player.c \
srcs/game/game.c \
srcs/game/initializations.c \
srcs/raycasting/raycasting.c \
srcs/raycasting/raycasting_utils.c \
srcs/raycasting/raycasting_render.c \
srcs/print_game/print_game.c \
srcs/print_game/minimap_system/print_2d.c

OBJS = ${SRCS:.c=.o}

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)
	@echo "$(PINK) 👾🎮 Cub3d ready!$(RESET)"

$(NAME): $(MLX) $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(MLX) $(MLX_FLAGS) $(LIBFT) -o $(NAME) -lm

$(LIBFT):
	@make -s -C $(LIBFT_PATH)
	@echo "$(BLUE) 📚 Libft is ready to be used$(RESET)"

$(MLX):
	@make -s -C $(MLX_PATH)
	@echo "$(BLUE) 📚 Minilibx is ready to be used$(RESET)"

clean:
	@rm -f $(OBJS)
	make clean -C $(LIBFT_PATH)
	@make clean -C $(MLX_PATH)
	@echo "$(BLUE) 📤 Objects deleted$(RESET)"

fclean: clean
		@rm -f $(NAME)
		@make fclean -C $(LIBFT_PATH)
		@echo "$(BLUE) 🧼 All cleaned$(RESET)"

re: fclean all

cube:
	./$(NAME) $(MAP)

run: re cube

norm:
	@echo "$(PURPLE)Passando a Norminette com a flag -R CheckForbiddenSourceHeader: $(RESET)"
	@-norminette -R CheckForbiddenSourceHeader

val: re
	valgrind  --leak-check=full --show-leak-kinds=all --track-fds=yes ./$(NAME) $(MAP)

val2:
	valgrind  --leak-check=full --show-leak-kinds=all --track-fds=yes ./$(NAME) $(MAP)

run2:
	./$(NAME) $(MAP)

container:
	exec docker container run -u root -ti -v $(CONTAINER_WORKDIR_PATH):/workspace devcontainer

test_error: re
	clear
	@$(foreach map,$(BAD_MAPS),echo processing: $(map); valgrind  --leak-check=full --show-leak-kinds=all --track-fds=yes ./$(NAME) $(map);)
	@echo "\n"
