/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadas <kadas@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 17:31:06 by kadas             #+#    #+#             */
/*   Updated: 2026/06/27 17:31:06 by kadas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3d.h"

void free_map(t_game *game)
{
	int i;

	i = 0;
	if (game->map)
	{
		i = 0;
		while (i < game->map_height)
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
	}
}
int	end_game(t_game *game)
{
	int	i;

	free_map(game);
	i = 0;
	while (i < 4)
	{
		if (game->textures[i].path)
			free(game->textures[i].path);
		i++;
	}
	if (game->img)
		mlx_destroy_image(game->mlx, game->img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
	return (0);
}

void	rotate(t_game *game, double ang)
{
	double	cos_ang;
	double	sin_ang;
	double	old_dir_x;
	double	old_plane_x;

	cos_ang = cos(ang);
	sin_ang = sin(ang);
	old_dir_x = game->pov.dir.x;
	old_plane_x = game->pov.plane.x;
	game->pov.dir.x = old_dir_x * cos_ang - game->pov.dir.y * sin_ang;
	game->pov.dir.y = old_dir_x * sin_ang + game->pov.dir.y * cos_ang;
	game->pov.plane.x = old_plane_x * cos_ang - game->pov.plane.y * sin_ang;
	game->pov.plane.y = old_plane_x * sin_ang + game->pov.plane.y * cos_ang;
}

int	key_press(int key, t_game *game)
{
	if (key == ESC)
		end_game(game);
	if (key == W || key == 'w')
		w_move(game);
	if (key == A || key == 'a')
		d_move(game);
	if (key == S || key == 's')
		s_move(game);
	if (key == D || key == 'd')
		a_move(game);
	if (key == LEFT)
		rotate(game, -ROTATE_SPEED);
	if (key == RIGHT)
		rotate(game, ROTATE_SPEED);
	return (0);
}
