/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadas <kadas@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 17:30:57 by kadas             #+#    #+#             */
/*   Updated: 2026/06/27 17:30:57 by kadas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3d.h"

void	init_mlx(t_game *game)
{
	int endian;

	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "Raycasting");
	
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->pixel.address = mlx_get_data_addr(game->img,
			&game->pixel.bitpp, &game->pixel.line_size, &endian);
}


