/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bridge.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmoman <aalmoman@amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 17:28:31 by kadas             #+#    #+#             */
/*   Updated: 2026/07/02 01:53:16 by aalmoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3d.h"

void	bridge_player(t_game *game)
{
	game->pov.pos.x = game->player.x;
	game->pov.pos.y = game->player.y;
	game->pov.dir.x = game->player.dir_x;
	game->pov.dir.y = game->player.dir_y;
	game->pov.plane.x = game->player.vision_x;
	game->pov.plane.y = game->player.vision_y;
}

void	bridge_textures(t_game *game)
{
	int		i;
	void	*img;
	int		endian;

	i = 0;
	while (i < 4)
	{
		img = mlx_xpm_file_to_image(game->mlx,
				game->textures[i].path,
				&game->images.walls[i].width,
				&game->images.walls[i].height);
		if (!img)
			exit(printf("Error\nFailed to load texture: %s\n",
					game->textures[i].path));
		game->images.walls[i].img = img;
		game->images.walls[i].address = mlx_get_data_addr(img,
				&game->images.walls[i].bitpp,
				&game->images.walls[i].line_size, &endian);
		i++;
	}
}
