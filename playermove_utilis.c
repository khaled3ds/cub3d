/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playermove_utilis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmoman <aalmoman@amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 22:29:27 by aalmoman          #+#    #+#             */
/*   Updated: 2026/06/30 22:30:37 by aalmoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3d.h"

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
void	w_move(t_game *game)
{
	if (is_valid(game, (int)(game->pov.pos.x + game->pov.dir.x * MOVE_SPEED), (int)game->pov.pos.y))
		game->pov.pos.x += game->pov.dir.x * MOVE_SPEED;
	if (is_valid(game, (int)game->pov.pos.x, (int)(game->pov.pos.y + game->pov.dir.y * MOVE_SPEED)))
		game->pov.pos.y += game->pov.dir.y * MOVE_SPEED;
}

void	a_move(t_game *game)
{
	if (is_valid(game, (int)(game->pov.pos.x - game->pov.dir.y * MOVE_SPEED), (int)game->pov.pos.y))
		game->pov.pos.x -= game->pov.dir.y * MOVE_SPEED;
	if (is_valid(game, (int)game->pov.pos.x, (int)(game->pov.pos.y + game->pov.dir.x * MOVE_SPEED)))
		game->pov.pos.y += game->pov.dir.x * MOVE_SPEED;
}

void	s_move(t_game *game)
{
	if (is_valid(game, (int)(game->pov.pos.x - game->pov.dir.x * MOVE_SPEED), (int)game->pov.pos.y))
		game->pov.pos.x -= game->pov.dir.x * MOVE_SPEED;
	if (is_valid(game, (int)game->pov.pos.x, (int)(game->pov.pos.y - game->pov.dir.y * MOVE_SPEED)))
		game->pov.pos.y -= game->pov.dir.y * MOVE_SPEED;
}

void	d_move(t_game *game)
{
	if (is_valid(game, (int)(game->pov.pos.x + game->pov.dir.y * MOVE_SPEED), (int)game->pov.pos.y))
		game->pov.pos.x += game->pov.dir.y * MOVE_SPEED;
	if (is_valid(game, (int)game->pov.pos.x, (int)(game->pov.pos.y - game->pov.dir.x * MOVE_SPEED)))
		game->pov.pos.y -= game->pov.dir.x * MOVE_SPEED;
}
