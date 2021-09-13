NAME		= so_long

SRCS        =	srcs/so_long.c \
				srcs/draw_tile.c \
				srcs/init_tiles.c \
				srcs/init_map.c \
				srcs/helpers.c \
				srcs/initialize.c \
				srcs/destroy_base.c \
				srcs/check_map.c \
				srcs/read_map.c \
				srcs/put_img.c \
				srcs/move.c \
				srcs/hooks.c \
				srcs/update.c \

OBJS		= $(SRCS:.c=.o)

CC			= gcc
RM			= rm -f
FLAGS		= -Wall -Wextra -Werror
LIBFT		= ./libft/libft.a
LIBS		= -L ./mlx -lmlx -lXext -lX11 -lm -lbsd
MLX		= mlx/Makefile.gen
INCLUDES	= -I./includes

# Colors
_END=$'\x1b[0m'
_BOLD=$''
_UNDER=$'\x1b[4m'
_REV=$'\x1b[7m'
_GREY=$'\x1b[30m'
_RED=$'\x1b[31m'
_GREEN=$'\x1b[32m'
_YELLOW=$'\x1b[33m'
_BLUE=$'\x1b[34m'
_PURPLE=$'\x1b[35m'
_CYAN=$'\x1b[36m'
_WHITE=$'\x1b[37m'

all:			$(NAME)

$(NAME):		$(MLX) $(OBJS)
				@$(CC) ${FLAGS} $(INCLUDES) $(SRCS) -o ${NAME} ${LIBS} $(LIBFT)

$(MLX):
				@$(MAKE) -C mlx
				@echo $(_BOLD)$(_CYAN)"mlx compiled"
				@$(MAKE) -C libft

clean:
				@$(MAKE) -C mlx clean
				@$(MAKE) -C libft clean
				@rm -rf $(OBJS) $(BONUS_OBJS)
				@echo $(_BOLD)$(_PURPLE)"object files removed"

fclean:			clean
				@rm -rf $(NAME) $(MLX) $(LIBFT)
				@echo $(_BOLD)$(_PURPLE)"binary removed"

re:				fclean $(NAME)

.PHONY:			all clean fclean re
