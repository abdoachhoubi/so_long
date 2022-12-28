/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachhoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:10:42 by aachhoub          #+#    #+#             */
/*   Updated: 2022/12/28 15:10:43 by aachhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int ac, char **av)
{
	t_game	game;
	char	*s;

	s = "Moves count = 0";
	if (ac != 2)
		message_exit(RED"Error: only accepts 2 arguments", 2);
	win_size(&game, av);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.x, game.y + SIZE, "Astro");
	initialize(&game);
	create_map_line(&game, av);
	game_controller(&game);
	if (valid_path(&game, av[1]) != 0)
		message_destroy(RED"Error: Invalid Path"RESET, 2, &game);
	display_count(&game, 0, 0);
	mlx_hook(game.win, 17, 1L << 2, destroy_win, &game);
	mlx_key_hook(game.win, key_pressed, &game);
	mlx_loop(game.mlx);
}
