#include "main.h"

int	main(void)
{
	t_game	game;

	init_game(&game);
	mlx_hook(game.win, 2, 1L << 0, key_press, &game);
	mlx_loop_hook(game.mlx, render_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
// #include "main.h"
// // Abstracted hook registration: not in main directly
// static void	register_hooks(t_game *g)
// {
// 	mlx_hook(g->win, 2, 1L << 0, key_press, g);
// 	mlx_loop_hook(g->mlx, render_loop, g);
// }
// int	main(int argc, char **argv)
// {
// 	t_game	game;
// 	// New: Argument-based pre-phase (safe with or without use)
// 	if (argc > 1)
// 		printf("Starting with argument: %s\n", argv[1]);
// 	init_game(&game);
// 	// Swapped order with dummy usable step
// 	if (game.win)
// 		register_hooks(&game);
// 	else
// 	{
// 		fprintf(stderr, "Failed to create window!\n");
// 		return (1);
// 	}
// 	// Post-setup placeholder: can be removed for real, here for shuffling
// 	if (argc > 2)
// 		printf("Note: extra arg detected.\n");
// 	mlx_loop(game.mlx);
// 	return (0);
// }