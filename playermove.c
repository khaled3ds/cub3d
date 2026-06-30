/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playermove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmoman <aalmoman@amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 22:30:26 by aalmoman          #+#    #+#             */
/*   Updated: 2026/06/30 22:30:26 by aalmoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3d.h"

int	is_valid(t_game *game, int x, int y)
{
	if (!game || !game->map)
		return (0);
	if (x < 0 || x >= game->map_width || y < 0 || y >= game->map_height)
		return (0);
	if (game->map[y][x] == '1')
		return (0);
	return (1);
}

void	move_player(t_game *game, int keycode)
{
	if (keycode == W || keycode == 'w')
		w_move(game);
	if (keycode == A || keycode == 'a')
		a_move(game);
	if (keycode == S || keycode == 's')
		s_move(game);
	if (keycode == D || keycode == 'd')
		d_move(game);
}
