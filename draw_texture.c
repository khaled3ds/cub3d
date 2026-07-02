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

void	draw_floor(t_game *game, int x, int y_end)
{
	int	y;

	y = game->drow.end + 1;
	while (y < y_end)
	{
		draw_pixel(game->pixel, x, y, game->floor_color);
		y++;
	}
}

void	draw_ceiling(t_game *game, int x, int y_end)
{
	int	y;

	y = 0;
	while (y < y_end)
	{
		draw_pixel(game->pixel, x, y, game->ceiling_color);
		y++;
	}
}

void	draw_wall(t_game *game, t_images *images, int x)
{
	t_wall_draw	wd;

	init_wall(game, images, &wd);
	draw_wall_loop(game, images, x, &wd);
}
