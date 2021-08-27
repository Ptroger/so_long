NAME		= so_long

SRCS        =	srcs/so_long.c \
				srcs/draw_tile.c \
				srcs/init_tiles.c \
				srcs/helpers.c

OBJS		= $(SRCS:.c=.o)

CC			= gcc
RM			= rm -f
FLAGS		= -Wall -Wextra -Werror
LIBS		= -framework OpenGL -framework AppKit -lm
MLX			= libmlx.dylib
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
				@$(CC) ${FLAGS} $(INCLUDES) $(SRCS) -o ${NAME} ${LIBS} $(MLX)
				@echo $(_BOLD)$(_GREEN)"so_long ready 🥑"

$(MLX):
				@$(MAKE) -C mlx
				@cp mlx/$(MLX) .
				@echo $(_BOLD)$(_CYAN)"mlx compiled"

clean:
				@$(MAKE) -C mlx clean
				@rm -rf $(OBJS) $(BONUS_OBJS)
				@echo $(_BOLD)$(_PURPLE)"object files removed"

fclean:			clean
				@rm -rf $(NAME) $(MLX)
				@echo $(_BOLD)$(_PURPLE)"binary removed"

re:				fclean $(NAME)

.PHONY:			all clean fclean re