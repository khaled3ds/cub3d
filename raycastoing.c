/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycastoing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadas <kadas@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 15:41:57 by kadas             #+#    #+#             */
/*   Updated: 2026/06/27 15:41:57 by kadas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3d.h"
static void	set_delta_dist(t_rayCasting *ray)
{
	if (ray->ray_dir.y == 0)
		ray->delta_dist.x = 0;
	else
	{
		if (ray->ray_dir.x == 0)
			ray->delta_dist.x = 1;
		else
			ray->delta_dist.x = fabs(1 / ray->ray_dir.x);
	}
	if (ray->ray_dir.x == 0)
		ray->delta_dist.y = 0;
	else
	{
		if (ray->ray_dir.y == 0)
			ray->delta_dist.y = 1;
		else
			ray->delta_dist.y = fabs(1 / ray->ray_dir.y);
	}
}

void do_DDA(t_game *game, double camera_x)
{
	game->ray.hit = 0;
	start_ray(game, camera_x);
	while (!game->ray.hit)
	{
		if (game->ray.side_dist.x < game->ray.side_dist.y)
			update_xray(game);
		else if (game->ray.side_dist.x > game->ray.side_dist.y)
			update_yray(game);
		else
		{
			update_xray(game);
			update_yray(game);
		}
		if (game->map[game->ray.map_pos.y][game->ray.map_pos.x] == '1')
			game->ray.hit = 1;
	}	
	if (game->ray.is_y_side == 0)
		game->ray.wall_dist = (game->ray.map_pos.x - game->pov.pos.x + (1 - game->ray.steps.x) / 2.0)
			/ game->ray.ray_dir.x;
	else
		game->ray.wall_dist = (game->ray.map_pos.y - game->pov.pos.y + (1 - game->ray.steps.y) / 2.0)
			/ game->ray.ray_dir.y;
}

void start_ray(t_game *game, double camera_x)
{
	game->ray.ray_dir.x = game->pov.dir.x + game->pov.plane.x * camera_x;
	game->ray.ray_dir.y = game->pov.dir.y + game->pov.plane.y * camera_x;
	game->ray.map_pos.x = (int)game->pov.pos.x;
	game->ray.map_pos.y = (int)game->pov.pos.y;
	set_delta_dist(&game->ray);
	move_dir(game);
	x_side_dist(game);
	y_side_dist(game);
}
