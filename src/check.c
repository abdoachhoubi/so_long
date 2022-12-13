#include "../inc/so_long.h"

// Checks which key is clicked
int	key_pressed(int code, t_game *game)
{
	if (code == ESC)
		destroy_win(game);
	if (code == UP)
		up(game);
	if (code == RIGHT)
		right(game);
	if (code == DOWN)
		down(game);
	if (code == LEFT)
		left(game);
	return (0);
}

// Checks the outcome of a move
int	move_check(t_game *game, int i, int j)
{
	if (game->map[i][j] == '1')
		return (1);
	else if (game->map[i][j] == 'C')
	{
		game->player.coin++;
		game->map[i][j] = '0';
	}
	else if (game->map[i][j] == 'E')
	{
		if (game->player.coin != game->check_coin)
		{
			ft_putendl_fd(RED"Bonus collected\n"RESET, 1);
			return (1);
		}
		message(GREEN"Congratulations uwu\n"RESET, 1, game);
		return (0);
	}
	return (0);
}
