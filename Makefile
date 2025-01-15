# Colors
RESET=\033[0m
PURPLE = \033[35m
GREEN=\033[32m
PINK=\033[35m
RED=\033[31m
BLUE=\033[34m

NAME = cub3d

COMPILER = cc

CFLAGS = -Wall -Wextra -Werror -g

MLX_FLAGS = -L/usr/lib/X11 -lXext -lX11

LIBFT_PATH = includes/my_libft

MLX_PATH = includes/mlx

LIBFT = $(LIBFT_PATH)/libft.a

MLX = $(MLX_PATH)/libmlx.a

CONTAINER_WORKDIR_PATH = "/Users/lraggio/Studies/my_container/"

#MAP = maps/map.cub
MAP = maps/good/matrix.cub
#MAP = maps/good/subject_map.cub
#MAP = maps/bad/empty.cub

SRCS = \
srcs/main.c \
srcs/map/map.c \
srcs/map/map_validation.c \
srcs/map/walls.c \
srcs/map/ceiling_and_floor.c \
srcs/game.c

OBJS = ${SRCS:.c=.o}

%.o: %.c
	@$(COMPILER) $(CFLAGS) -c $< -o $@

all: $(NAME)
	@echo "$(PINK) 👾🎮 Cub3d ready!$(RESET)"

$(NAME): $(MLX) $(LIBFT) $(OBJS)
	@$(COMPILER) $(CFLAGS) $(MLX_FLAGS) $(OBJS) $(LIBFT) $(MLX) -o $(NAME)

$(LIBFT):
	@make -s -C $(LIBFT_PATH)
	@echo "$(BLUE) 📚 libft is ready to be used$(RESET)"

$(MLX):
	@make -s -C $(MLX_PATH)
	@echo "$(BLUE) 📚 minilibx is ready to be used$(RESET)"

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

run: re
	./$(NAME) $(MAP)

norm:
	@echo "$(PURPLE)Passando a Norminette com a flag -R CheckForbiddenSourceHeader: $(RESET)"
	@-norminette -R CheckForbiddenSourceHeader

val: re
	valgrind  --leak-check=full --show-leak-kinds=all --track-fds=yes ./$(NAME) $(MAP)

container:
	exec docker container run -u root -ti -v $(CONTAINER_WORKDIR_PATH):/workspace devcontainer
