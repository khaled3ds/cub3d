#include "main.h"

void	y_side_dist(t_game *game)
{
	if (game->ray.ray_dir.y < 0)
		game->ray.side_dist.y = (game->pov.pos.y - (double)game->ray.map_pos.y) * game->ray.delta_dist.y;
	else
		game->ray.side_dist.y = (game->ray.map_pos.y + 1.0 - game->pov.pos.y) * game->ray.delta_dist.y;
}

void x_side_dist(t_game *game)
{
	if (game->ray.ray_dir.x < 0)
		game->ray.side_dist.x = (game->pov.pos.x - (double)game->ray.map_pos.x) * game->ray.delta_dist.x;
	else
		game->ray.side_dist.x = (game->ray.map_pos.x + 1.0 - game->pov.pos.x) * game->ray.delta_dist.x;
}

void	move_dir(t_game *game)
{
	if (game->ray.ray_dir.x < 0)
		game->ray.steps.x = -1;
	else
		game->ray.steps.x = 1;
	if (game->ray.ray_dir.y < 0)
		game->ray.steps.y = -1;
	else
		game->ray.steps.y = 1;
}
void update_xray(t_game *game)
{
	game->ray.side_dist.x += game->ray.delta_dist.x;
	game->ray.map_pos.x += game->ray.steps.x;
	game->ray.is_y_side = 0;
}

void update_yray(t_game *game)
{
	game->ray.side_dist.y += game->ray.delta_dist.y;
	game->ray.map_pos.y += game->ray.steps.y;
	game->ray.is_y_side = 1;
}
