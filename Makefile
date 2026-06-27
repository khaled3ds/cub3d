NAME = cub3d

SRCS =	main.c bridge.c mlx_init.c render.c render_utiles.c draw_texture.c \
		raycasting_utilis.c raycastoing.c playermove.c hooks_handler.c \
		parse/parse_data.c parse/read_map.c parse/vaildation.c \
		parse/init_player.c parse/utils.c \
		header/get_next_line.c header/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
LDFLAGS	= -Lminilibx-linux -lmlx -lX11 -lXext -lm -Llibft -lft

all: minilibx-linux/libmlx.a libft/libft.a $(NAME)

minilibx-linux/libmlx.a:
	make -C minilibx-linux

libft/libft.a:
	make -C libft

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re