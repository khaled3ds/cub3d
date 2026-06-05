/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 20:44:32 by kadas             #+#    #+#             */
/*   Updated: 2026/06/05 10:36:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/game.h"

static void	spawn_directions2(t_game *game, char c)
{
	if (c == 'E')
	{
		game->parser.player.dir_x = 1;
		game->parser.player.dir_y = 0;
		game->parser.player.vision_x = 0;
		game->parser.player.vision_y = 0.66;
	}
	else if (c == 'W')
	{
		game->parser.player.dir_x = -1;
		game->parser.player.dir_y = 0;
		game->parser.player.vision_x = 0;
		game->parser.player.vision_y = -0.66;
	}
}

static void	spawn_directions(t_game *game, char c)
{
	if (c == 'N')
	{
		game->parser.player.dir_x = 0;
		game->parser.player.dir_y = -1;
		game->parser.player.vision_x = 0.66;
		game->parser.player.vision_y = 0;
	}
	else if (c == 'S')
	{
		game->parser.player.dir_x = 0;
		game->parser.player.dir_y = 1;
		game->parser.player.vision_x = -0.66;
		game->parser.player.vision_y = 0;
	}
	else
		spawn_directions2(game, c);
}

void	init_player(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->parser.map[i])
	{
		j = 0;
		while (game->parser.map[i][j])
		{
			if (game->parser.map[i][j] == 'N' || game->parser.map[i][j] == 'S'
				|| game->parser.map[i][j] == 'E' || game->parser.map[i][j] == 'W')
			{
				game->parser.player.y = i + 0.5;
				game->parser.player.x = j + 0.5;
				spawn_directions(game, game->parser.map[i][j]);
				game->parser.map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
}
