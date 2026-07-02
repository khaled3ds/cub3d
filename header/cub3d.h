/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmoman <aalmoman@amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 03:04:51 by aalmoman          #+#    #+#             */
/*   Updated: 2026/07/02 03:08:00 by aalmoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef CUB3D_H
# define CUB3D_H
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define WIDTH 1280
# define HEIGHT 720
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define NO 0
# define SO 1
# define WE 2
# define EA 3

# define W 119
# define A 97
# define S 115
# define D 100
# define ESC 65307
# define LEFT 65361
# define RIGHT 65363

# define MOVE_SPEED 0.01
# define ROTATE_SPEED 0.04
typedef struct s_daxis
{
	double	x;
	double	y;
}	t_dAxis;

typedef struct s_iaxis
{
	int	x;
	int	y;
}	t_iAxis;
typedef struct s_pixel
{
	char	*address;
	int		bitpp;
	int		line_size;
}	t_pixel;
typedef enum e_side
{
	south,
	east,
	west,
	north
}	t_side;
typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	vision_x;
	double	vision_y;
}	t_player;
typedef struct s_texture
{
	char	*path;
	char	*address;
	void	*img;
	int		width;
	int		height;
	int		bitpp;
	int		line_size;
}	t_texture;
typedef struct s_raycasting
{
	t_dAxis		ray_dir;
	t_dAxis		delta_dist;
	t_dAxis		side_dist;
	t_iAxis		map_pos;
	t_iAxis		steps;
	double		wall_dist;
	int			is_y_side;
	double		ratio;
	int			hit;
	t_side		side;
}	t_rayCasting;
typedef struct s_pov
{
	t_dAxis	pos;
	t_dAxis	dir;
	t_dAxis	plane;
}	t_pov;
typedef struct s_drow
{
	int	end;
	int	start;
	int	wall_height;
}	t_drow;
typedef struct s_images
{
	t_texture	walls[4];
	t_texture	ceiling;
	t_texture	floor;
}	t_images;
typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*img;
	t_pixel		pixel;
	t_pov		pov;
	t_rayCasting	ray;
	t_drow		drow;
	t_side		hit_side;
	t_images	images;
	char		**map;
	int			map_width;
	int			map_height;
	int			floor_color;
	int			ceiling_color;
	int			has_floor;
	int			has_ceiling;
	t_texture	textures[4];
	t_player	player;
	int		keys[65400];
}	t_game;

typedef struct s_wall_draw
{
	int		y;
	int		tex_y;
	double	step;
	double	tex_pos;
	int		color;
	int		wall_tex_x;
	t_side	side;
}	t_wall_draw;

char	*get_next_line(int fd);
char	**inputer(char *cub);
int		key_release(int key, t_game *game);
void	handle_keys(t_game *game);
void	parse_data(t_game *game, char **file);
void	color_parser_helper(int arr[], char *substring);
void	path_checker(t_game *game, int i);
void	free_all(char **words);
void	free_game(t_game *game);
int		isvalid(char **map);
int		valid_char(char **map);
void	init_player(t_game *game);
void	bridge_player(t_game *game);
void	bridge_textures(t_game *game);
void	init_mlx(t_game *game);
void	y_side_dist(t_game *game);
void	x_side_dist(t_game *game);
void	move_dir(t_game *game);
void	update_xray(t_game *game);
void	update_yray(t_game *game);
void	do_dda(t_game *game);
void	start_ray(t_game *game, double camera_x);
int		get_texture_color(t_texture *tex, int tex_x, int tex_y);
void	get_side(t_game *game);
void	get_drow_start_end(t_game *game);
int		render(t_game *game);
int		render_loop(void *param);
int		get_wall_tex_x(t_game *game);
void	draw_pixel(t_pixel pixel, int x, int y, int color);
void	draw_ceiling(t_game *game, int x, int y_end);
void	draw_floor(t_game *game, int x, int y_end);
void	init_wall(t_game *game, t_images *images, t_wall_draw *wd);
void	draw_wall_loop(t_game *game, t_images *images, int x, t_wall_draw *wd);
void	draw_wall(t_game *game, t_images *images, int x);
void	free_map(t_game *game);
void	w_move(t_game *game);
void	a_move(t_game *game);
void	s_move(t_game *game);
void	d_move(t_game *game);
void	rotate(t_game *game, double ang);
int		end_game(t_game *game);
int		key_press(int key, t_game *game);
void	move_player(t_game *game, int keycode);
int		is_valid(t_game *game, int x, int y);
void	update_wall_dist(t_game	*game);
void	tex_checker(t_game *game, char **file, int i, int len);
void	map_parser(char **file, int i, t_game *game);

#endif