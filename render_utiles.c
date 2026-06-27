/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utiles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadas <kadas@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 15:42:05 by kadas             #+#    #+#             */
/*   Updated: 2026/06/27 15:42:05 by kadas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3d.h"
void get_side(t_game *game)
{
	if (!game)
		return ;
	if (game->ray.is_y_side == 0 && game->ray.ray_dir.x > 0)
		game->ray.side = east;
	else if (game->ray.is_y_side == 0 && game->ray.ray_dir.x < 0)
		game->ray.side = west;
	else if (game->ray.is_y_side == 1 && game->ray.ray_dir.y > 0)
		game->ray.side = south;
	else if (game->ray.is_y_side == 1 && game->ray.ray_dir.y < 0)
		game->ray.side = north;
}

void get_drow_start_end(t_game *game)
{
	if (!game || game->ray.wall_dist <= 0)
		return ;
	game->drow.wall_height = (int)(HEIGHT / game->ray.wall_dist);
	if (game->drow.wall_height > HEIGHT)
		game->drow.wall_height = HEIGHT;
	game->drow.start = (HEIGHT - game->drow.wall_height) / 2;
	game->drow.end = game->drow.start + game->drow.wall_height;
}


void	draw_pixel(t_pixel pixel, int x, int y, int color) //this for drawing one pixel of the image per loop
{
	char	*dst;

	dst = pixel.address + (y * pixel.line_size + x * (pixel.bitpp / 8));
	*(unsigned int *)dst = color;
}