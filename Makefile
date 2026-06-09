NAME = raycast

SRCS = main.c mlx_init.c render.c render_utiles.c draw_texture.c raycasting_utilis.c raycastoing.c playermove.c hooks_handler.c

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -O2
LDFLAGS = -lmlx -lX11 -lXext -lm

all: $(NAME)

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
