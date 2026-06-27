/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadas <kadas@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 17:31:10 by kadas             #+#    #+#             */
/*   Updated: 2026/06/27 17:31:10 by kadas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3d.h"

int	get_texture_color(t_texture *tex, int tex_x, int tex_y)
{
	char	*dst;

	dst = tex->address + (tex_y * tex->line_size + tex_x * (tex->bitpp / 8));
	return (*(unsigned int *)dst);
}

void	draw_floor(t_pixel pixel, int x, int y_start, int y_end, t_images *images)
{
	int	y;
	int	tex_x;
	int	tex_y;
	int	color;

	y = y_start;
	while (y < y_end)
	{
		tex_x = (x % images->floor.width);
		tex_y = ((y - y_start) % images->floor.height);
		color = get_texture_color(&images->floor, tex_x, tex_y);
		draw_pixel(pixel, x, y, color);
		y++;
	}
}

void	draw_wall(t_game *game, t_images *images)//argument num exceed make a function for the initilization and one for the loop and a main one for the call
{
	int	y;
	int	tex_y;
	double	step;
	double	tex_pos;
	int	color;
	int	wall_tex_x;
	t_side	side;

	side = game->ray.side;
	wall_tex_x = get_wall_tex_x(game);
	step = (double)images->walls[side].height / (double)game->drow.wall_height;
	tex_pos = (game->drow.start - HEIGHT / 2 + game->drow.wall_height / 2) * step;
	y = game->drow.start;
	while (y <= game->drow.end)
	{
		tex_y = (int)tex_pos;
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= images->walls[side].height)
			tex_y = images->walls[side].height - 1;
		color = get_texture_color(&images->walls[side], wall_tex_x, tex_y);
		draw_pixel(game->pixel, 0, y, color);
		tex_pos += step;
		y++;
	}
}
void	draw_ceiling(t_pixel pixel, int x, int y_start, int y_end, t_images *images)
{
	int	y;
	int	tex_x;
	int	tex_y;
	int	color;

	y = y_start;
	while (y < y_end)
	{
		tex_x = (x % images->ceiling.width);
		tex_y = (y % images->ceiling.height);
		color = get_texture_color(&images->ceiling, tex_x, tex_y);
		draw_pixel(pixel, x, y, color);
		y++;
	}
}
