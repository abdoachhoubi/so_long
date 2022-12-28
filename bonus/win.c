/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachhoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:28:36 by aachhoub          #+#    #+#             */
/*   Updated: 2022/12/28 15:29:51 by aachhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	destroy_win(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	message_destroy(YELLOW"Game closed"RESET, 1, game);
	destroy_map(game);
	exit(EXIT_SUCCESS);
}

void	win_size(t_game *game, char **av)
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		message_exit(RED"Error:\nFile not found"RESET, 2);
	if (ft_strnstr(av[1], ".ber", ft_strlen(av[1])) == NULL)
		message_exit(RED"Error:\nMap file must end with .ber"RESET, 2);
	game->x = (line_length(fd) * SIZE);
	game->y = lines_count(fd) * SIZE;
	close(fd);
}
