#ifndef RAYCASTING_H
#define RAYCASTING_H

#define WIDTH 1280
#define HEIGHT 720

#include <math.h>

typedef struct s_daxis
{
	double x;
	double y;
} t_dAxis;

typedef struct s_iaxis
{
	int x;
	int y;
} t_iAxis;

typedef enum s_side
{
	south,
	east,
	west,
	north
} t_side;
typedef struct s_raycasting
{
	t_dAxis ray_dir;
	t_dAxis delta_dist;
	t_dAxis side_dist;
	t_iAxis map_pos;
	t_iAxis steps;
	double wall_dist;
	int is_y_side;
	double ratio;
	int hit;
	t_side side;
} t_rayCasting;

typedef struct s_pov
{
	t_dAxis	pos;
	t_dAxis	dir;
	t_dAxis	plane;
}	t_pov;

typedef struct s_drow
{
int end;
int start;
int wall_height;
} t_drow;

typedef struct s_pixel
{
	char *address;
	int bitpp;
	int line_size;
} t_pixel;

typedef struct s_game t_game;
void	y_side_dist(t_game *game);
void	x_side_dist(t_game *game);
void	move_dir(t_game *game);
void	update_xray(t_game *game);
void	update_yray(t_game *game);
void	do_DDA(t_game *game, double camera_x);
void	start_ray(t_game *game, double camera_x);

#endif