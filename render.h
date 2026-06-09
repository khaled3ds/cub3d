#ifndef RENDER_H
# define RENDER_H

# include "raycasting.h"

typedef struct s_texture
{
	char	*address;
	int	width;
	int	height;
	int	line_size;
	int	bitpp;
} t_texture;

typedef struct s_images
{
	t_texture	walls[4];
	t_texture	ceiling;
	t_texture	floor;
} t_images;

typedef struct s_draw
{
	t_pixel		pixel;
	int		x;
	t_drow		drow;
	t_images	*images;
	t_side		side;
	int		wall_tex_x;
} t_draw;

int			get_texture_color(t_texture *tex, int tex_x, int tex_y);
void		get_side(t_game *game);
void		get_drow_start_end(t_game *game);
int			render(t_game *game);
int			render_loop(void *param);
int			get_wall_tex_x(t_game *game);
void		draw_pixel(t_pixel pixel, int x, int y, int color);
void		draw_ceiling(t_pixel pixel, int x, int y_start, int y_end, t_images *images);
void		draw_floor(t_pixel pixel, int x, int y_start, int y_end, t_images *images);
void		draw_wall(t_game *game, t_images *images);

#endif