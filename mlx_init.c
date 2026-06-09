#include "main.h"

void load_floor(t_game *game)
{
	game->images.floor.address = mlx_get_data_addr(
		mlx_xpm_file_to_image(game->mlx, "texture/floors (1).xpm",
			&game->images.floor.width, &game->images.floor.height),
		&game->images.floor.bitpp, &game->images.floor.line_size, 0);
}

void	load_ceiling(t_game *game)
{
	game->images.ceiling.address = mlx_get_data_addr(
		mlx_xpm_file_to_image(game->mlx, "texture/celling (1).xpm",
			&game->images.ceiling.width, &game->images.ceiling.height),
		&game->images.ceiling.bitpp, &game->images.ceiling.line_size, 0);
}
void load_walls(t_game *game)
{
	game->images.walls[0].address = mlx_get_data_addr(
		mlx_xpm_file_to_image(game->mlx, "texture/walls (3).xpm",
			&game->images.walls[0].width, &game->images.walls[0].height),
		&game->images.walls[0].bitpp, &game->images.walls[0].line_size, 0);
	
	game->images.walls[1].address = mlx_get_data_addr(
		mlx_xpm_file_to_image(game->mlx, "texture/walls (3).xpm",
			&game->images.walls[1].width, &game->images.walls[1].height),
		&game->images.walls[1].bitpp, &game->images.walls[1].line_size, 0);
	
	game->images.walls[2].address = mlx_get_data_addr(
		mlx_xpm_file_to_image(game->mlx, "texture/walls (3).xpm",
			&game->images.walls[2].width, &game->images.walls[2].height),
		&game->images.walls[2].bitpp, &game->images.walls[2].line_size, 0);
	
	game->images.walls[3].address = mlx_get_data_addr(
		mlx_xpm_file_to_image(game->mlx, "texture/walls (3).xpm",
			&game->images.walls[3].width, &game->images.walls[3].height),
		&game->images.walls[3].bitpp, &game->images.walls[3].line_size, 0);
}

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "Raycasting");
	
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->pixel.address = mlx_get_data_addr(game->img,
			&game->pixel.bitpp, &game->pixel.line_size, 0);
}

void	init_game(t_game *game)
{
	init_mlx(game);
	game->map = NULL;
	load_walls(game);
	load_floor(game);
	load_ceiling(game);
}

