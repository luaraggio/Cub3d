NAME = cub3d
NAME_BONUS = cub3d_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLX_FLAGS = -L/usr/lib/X11 -lXext -lX11
LIBFT_PATH = includes/my_libft
MLX_PATH = includes/mlx
LIBFT = $(LIBFT_PATH)/libft.a
MLX = $(MLX_PATH)/libmlx.a

# Colors
RESET=\033[0m
PURPLE=\033[35m
GREEN=\033[32m
PINK=\033[35m
RED=\033[31m
BLUE=\033[34m

BAD_MAPS = ${shell find ./maps/bad}
GOOD_MAPS = ${shell find ./maps/good}

#MAP = maps/good/test_map.cub
#MAP = maps/good/big.cub
#MAP = maps/good/library.cub
#MAP = maps/good/matrix.cub
#MAP = maps/good/test_pos_bottom.cub;
#MAP = maps/good/test_whitespace.cub
MAP = maps/good/subject_map.cub
#MAP = maps/bad/empty.cub
#MAP = maps/bad/map_not_closed_with_walls_4.cub
#MAP = maps/bad/test_map.cub

SRCS = \
srcs/main.c \
srcs/map/map.c \
srcs/map/initializations.c \
srcs/utils/general_clear.c \
srcs/utils/clear_textures.c \
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
srcs/map/texture_extension.c \
srcs/map/color.c \
srcs/map/copy_map.c \
srcs/map/check_zeros_outside.c \
srcs/player/keys.c \
srcs/player/moves.c \
srcs/player/rotate.c \
srcs/player/player.c \
srcs/game/game.c \
srcs/game/initializations.c \
srcs/raycasting/raycasting.c \
srcs/raycasting/raycasting_utils.c \
srcs/raycasting/raycasting_render.c \
srcs/print_game/print_game.c

SRCS_BONUS = \
bonus/main.c \
bonus/map/map.c \
bonus/map/initializations.c \
bonus/utils/general_clear.c \
bonus/utils/clear_textures.c \
bonus/map/get_map_data.c \
bonus/map/map_validation.c \
bonus/map/rgb.c \
bonus/map/walls.c \
bonus/map/ceiling_and_floor.c \
bonus/map/is_map.c \
bonus/map/char_validation.c \
bonus/map/line_is.c \
bonus/map/floodfill.c \
bonus/map/texture.c \
bonus/map/texture_extension.c \
bonus/map/color.c \
bonus/map/copy_map.c \
bonus/map/check_zeros_outside.c \
bonus/player/keys.c \
bonus/player/moves.c \
bonus/player/rotate.c \
bonus/player/player.c \
bonus/game/game.c \
bonus/game/initializations.c \
bonus/raycasting/raycasting.c \
bonus/raycasting/raycasting_utils.c \
bonus/raycasting/raycasting_render.c \
bonus/print_game/minimap_system/print_2d_bonus.c \
bonus/print_game/minimap_system/print_2d_utils_bonus.c \
bonus/print_game/print_game_bonus.c

OBJS = ${SRCS:.c=.o}
OBJS_BONUS = ${SRCS_BONUS:.c=.o}

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)
	@echo "$(PINK) 👾🎮 Cub3d ready!$(RESET)"

bonus: $(NAME_BONUS)
	@echo "$(GREEN) 🎮 Bonus Cub3d ready!$(RESET)"

$(NAME): $(MLX) $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(MLX) $(MLX_FLAGS) $(LIBFT) -o $(NAME) -lm

$(NAME_BONUS): $(MLX) $(LIBFT) $(OBJS_BONUS)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(MLX) $(MLX_FLAGS) $(LIBFT) -o $(NAME_BONUS) -lm

$(LIBFT):
	@make -s -C $(LIBFT_PATH)
	@echo "$(BLUE) 📚 Libft is ready to be used$(RESET)"

$(MLX):
	@make -s -C $(MLX_PATH)
	@echo "$(BLUE) 📚 Minilibx is ready to be used$(RESET)"

clean:
	@rm -f $(OBJS) $(OBJS_BONUS)
	make clean -C $(LIBFT_PATH)
	@make clean -C $(MLX_PATH)
	@echo "$(BLUE) 📤 Objects deleted$(RESET)"

fclean: clean
		@rm -f $(NAME) $(NAME_BONUS)
		@make fclean -C $(LIBFT_PATH)
		@echo "$(BLUE) 🧼 All cleaned$(RESET)"

re: fclean all

re_bonus: fclean bonus

cube:
	./$(NAME) $(MAP)

run: re cube

run_bonus: re_bonus
	./$(NAME_BONUS) $(MAP)

norm:
	@echo "$(PURPLE)Passing Norminette with flag -R CheckForbiddenSourceHeader: $(RESET)"
	@-norminette -R CheckForbiddenSourceHeader $(SRCS) $(SRCS_BONUS) includes/cub3d.h includes/my_libft includes/enums.h includes/structs.h includes/cub3d_bonus.h

val: re
	valgrind  --leak-check=full --show-leak-kinds=all --track-fds=yes ./$(NAME) $(MAP)

val2:
	valgrind  --leak-check=full --show-leak-kinds=all --track-fds=yes ./$(NAME) $(MAP)

val_bonus: re_bonus
	valgrind  --leak-check=full --show-leak-kinds=all --track-fds=yes ./$(NAME_BONUS) $(MAP)

run2:
	./$(NAME) $(MAP)

test_error: re
	clear
	@$(foreach map,$(BAD_MAPS),echo processing: $(map); valgrind  --leak-check=full --show-leak-kinds=all --track-fds=yes ./$(NAME) $(map);)
	@echo "\n"

test_all: re
	clear
	@$(foreach map,$(GOOD_MAPS),echo processing: $(map); valgrind  --leak-check=full --show-leak-kinds=all --track-fds=yes ./$(NAME) $(map);)
	@echo "\n"

test_all_bonus: re_bonus
	clear
	@$(foreach map,$(GOOD_MAPS),echo processing: $(map); valgrind  --leak-check=full --show-leak-kinds=all --track-fds=yes ./$(NAME_BONUS) $(map);)
	@echo "\n"