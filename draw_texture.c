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

void	draw_floor(t_pixel pixel, int x, int y_start, int y_end, int color)
{
	int	y;

	y = y_start;
	while (y < y_end)
	{
		draw_pixel(pixel, x, y, color);
		y++;
	}
}

void	draw_ceiling(t_pixel pixel, int x, int y_start, int y_end, int color)
{
	int	y;

	y = y_start;
	while (y < y_end)
	{
		draw_pixel(pixel, x, y, color);
		y++;
	}
}

void	draw_wall(t_game *game, t_images *images, int x)
{
	t_wall_draw	wd;

	init_wall(game, images, &wd);
	draw_wall_loop(game, images, x, &wd);
}