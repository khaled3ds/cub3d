/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utilis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmoman <aalmoman@amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 22:33:30 by aalmoman          #+#    #+#             */
/*   Updated: 2026/06/30 22:34:32 by aalmoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3d.h"

void	init_wall(t_game *game, t_images *images, t_wall_draw *wall)
{
	wall->side = game->ray.side;
	wall->wall_tex_x = get_wall_tex_x(game);
	wall->step = (double)images->walls[wall->side].height
		/ (double)game->drow.wall_height;
	wall->tex_pos = (game->drow.start - HEIGHT / 2
			+ game->drow.wall_height / 2) * wall->step;
	wall->y = game->drow.start;
}

void	draw_wall_loop(t_game *game, t_images *images, int x, t_wall_draw *wall)
{
	while (wall->y <= game->drow.end)
	{
		wall->tex_y = (int)wall->tex_pos;
		if (wall->tex_y < 0)
			wall->tex_y = 0;
		if (wall->tex_y >= images->walls[wall->side].height)
			wall->tex_y = images->walls[wall->side].height - 1;
		wall->color = get_texture_color(&images->walls[wall->side],
				wall->wall_tex_x, wall->tex_y);
		draw_pixel(game->pixel, x, wall->y, wall->color);
		wall->tex_pos += wall->step;
		wall->y++;
	}
}

int	get_texture_color(t_texture *tex, int tex_x, int tex_y)
{
	char	*dst;

	dst = tex->address + (tex_y * tex->line_size + tex_x * (tex->bitpp / 8));
	return (*(unsigned int *)dst);
}
