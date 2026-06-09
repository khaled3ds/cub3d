#ifndef MOVEMENT_H
#define MOVEMENT_H

# define W 119
# define A 97
# define S 115
# define D 100
# define ESC 65307
# define LEFT 65361
# define RIGHT 65363
# define MOVE_SPEED 0.05
# define ROTATE_SPEED 0.04

typedef struct s_game t_game;

void 	free_map(t_game *game);
void	w_move(t_game *game);
void	a_move(t_game *game);
void	s_move(t_game *game);
void	d_move(t_game *game);
void	rotate(t_game *game, double ang);
int		end_game(t_game *game);

#endif