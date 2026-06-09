#include "main.h"

static int	is_valid(t_game *game, int x, int y)
{
	if (!game || !game->map)
		return (0);
	if (x < 0 || x >= game->map_width || y < 0 || y >= game->map_height)
		return (0);
	if (game->map[y][x] == '1')
		return (0);
	return (1);
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