#ifndef MAIN_H
# define MAIN_H

# include "raycasting.h"
# include "render.h"
# include "movement.h"
# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include <stddef.h>
# include <math.h>

typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*img;
	t_pixel		pixel;
	t_pov		pov;
	t_rayCasting	ray;
	t_drow		drow;
	t_side		side;
	t_images	images;
	char		**map;
	int		map_width;
	int		map_height;
}	t_game;

void	init_game(t_game *game);
void	init_mlx(t_game *game);
void	load_floor(t_game *game);
void	load_walls(t_game *game);
void	load_ceiling(t_game *game);
int		render_frame(t_game *game);
int		key_press(int key, t_game *game);
void	move_player(t_game *game, int keycode);

#endif
