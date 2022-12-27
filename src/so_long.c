#include "../inc/so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		message(RED"Only accepts 2 arguments", 2, &game);
	win_size(&game, av);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.x, game.y, "Astro");
	initialize(&game);
	create_map_line(&game, av);
	game_controller(&game);
	if (valid_path(&game, av[1]) != 0)
		message(RED"Error: Invalid Path"RESET, 2, &game);
	mlx_hook(game.win, 17, 1L << 2, destroy_win, &game);
	mlx_key_hook(game.win, key_pressed, &game);
	mlx_loop(game.mlx);
}
