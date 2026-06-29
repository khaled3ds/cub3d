/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadas <kadas@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 17:31:02 by kadas             #+#    #+#             */
/*   Updated: 2026/06/27 17:31:02 by kadas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;
	char	**file;

	if (argc != 2)
		return (write(2, "Error\nUsage: ./cub3d map.cub\n", 29));
	ft_memset(&game, 0, sizeof(t_game));
	file = inputer(argv[1]);
	parse_data(&game, file);
	free_all(file);
	if (!isvalid(game.map))
	{
		free_game(&game);
		return (write(2, "Error\nInvalid map\n", 18));
	}
	init_player(&game);
	init_mlx(&game);
	bridge_player(&game);
	bridge_textures(&game);
	mlx_hook(game.win, 2, 1L << 0, key_press, &game);
	mlx_hook(game.win, 3, 1L << 1, key_release, &game);
	mlx_hook(game.win, 17, 0, end_game, &game);
	mlx_loop_hook(game.mlx, render_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
