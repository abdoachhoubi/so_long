/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachhoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:04:06 by aachhoub          #+#    #+#             */
/*   Updated: 2022/12/28 15:05:12 by aachhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// Handles key clicks
int	key_pressed(int code, t_game *game)
{
	if (code == ESC)
		destroy_win(game);
	if (code == UP1 || code == UP2)
		up(game);
	if (code == RIGHT1 || code == RIGHT2)
		right(game);
	if (code == DOWN1 || code == DOWN2)
		down(game);
	if (code == LEFT1 || code == LEFT2)
		left(game);
	return (0);
}

// Opens the exit door
void	open_exit(t_game *game)
{
	t_image	image;

	image.path = "./res/open.xpm";
	image.game = *game;
	put_image(image, game->exit_coordinates[0], game->exit_coordinates[1]);
}

// Handles moves
int	move_check(t_game *game, int i, int j)
{
	if (game->map[i][j] == '1')
		return (1);
	else if (game->map[i][j] == 'C')
	{
		game->player.coin++;
		game->map[i][j] = '0';
		if (game->check_coin == game->player.coin)
			open_exit(game);
	}
	else if (game->map[i][j] == 'E')
	{
		if (game->player.coin != game->check_coin)
		{
			ft_putendl_fd(RED"You must collect all coins"RESET, 1);
			return (1);
		}
		message_destroy(GREEN"Congratulations uwu\n"RESET, 1, game);
		return (0);
	}
	return (0);
}
