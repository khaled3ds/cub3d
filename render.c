/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadas <kadas@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 15:42:10 by kadas             #+#    #+#             */
/*   Updated: 2026/06/27 15:42:10 by kadas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3d.h"
static void	draw_tex(t_game *game, int x)
{
	if (game->drow.start < 0)
		game->drow.start = 0;
	if (game->drow.end >= HEIGHT)
		game->drow.end = HEIGHT - 1;
	draw_ceiling(game->pixel, x, 0, game->drow.start, game->ceiling_color);
	draw_wall(game, &game->images, x);
	draw_floor(game->pixel, x, game->drow.end + 1, HEIGHT, game->floor_color);
}


int	get_wall_tex_x(t_game *game)
{
	double	wall_x;
	int		tex_x;

	if (game->ray.is_y_side == 0)
		wall_x = game->pov.pos.y + game->ray.wall_dist * game->ray.ray_dir.y;
	else
		wall_x = game->pov.pos.x + game->ray.wall_dist * game->ray.ray_dir.x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)game->images.walls[game->ray.side].width);
	if ((game->ray.is_y_side == 0 && game->ray.ray_dir.x > 0)
		|| (game->ray.is_y_side == 1 && game->ray.ray_dir.y < 0))
		tex_x = game->images.walls[game->ray.side].width - tex_x - 1;
	return (tex_x);
}

static void	draw_col(t_game *game, int x)
{
	double camera_x = 2.0 * x / (double)WIDTH - 1.0;
	
	do_DDA(game, camera_x);
	get_side(game);
	get_drow_start_end(game);
	game->hit_side = game->ray.side;
	draw_tex(game, x);
}

int 	render(t_game *game)
{
	int x = -1;
	
	while (++x < WIDTH)
		draw_col(game, x);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	return (0);
}

int	render_loop(void *param)
{
	return (render((t_game *)param));
}

