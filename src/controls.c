#include "../inc/so_long.h"

// Controlls the walls
void	wall_controller(t_game *game)
{
	size_t	x;
	int		y;
	char	*s;

	s = RED"Error:\nThe map must be surrounded by walls\n"RESET;
	y = 0;
	while (y < (game->y / SIZE))
	{
		x = 0;
		while (x < (game->x / SIZE))
		{
			if ((y == 0 || x == 0) && game->map[y][x] != '1')
				message(s, 2, game);
			else if ((y == (game->y / SIZE - 1)
					|| x == (game->x / SIZE - 1))
				&& game->map[y][x] != '1')
				message(s, 2, game);
			x++;
		}
		y++;
	}
}

// controlls the whole map
void	map_controller(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'E')
				game->check_exit++;
			j++;
		}
		i++;
	}
	if (game->check_coin == 0)
		message(RED"Error:\nThere are no coins in the map!\n"RESET, 2, game);
	if (game->check_exit == 0)
		message(RED"Error:\nThere is no exit door on the map!\n"RESET, 2, game);
	if (game->check_player != 1)
		message(RED"Error:\nOnly one player is allowed\n"RESET, 2, game);
}

// Controls the game
void	game_controller(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
					game->check_coin++;
			if (game->map[i][j] == 'P')
			{
				game->player.x = j * SIZE;
				game->player.y = i * SIZE;
				game->check_player++;
			}
			j++;
		}
		i++;
	}
	map_controller(game);
	wall_controller(game);
}
