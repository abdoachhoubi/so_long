#include "../inc/so_long.h"

void	destroy_map(t_game	*game)
{
	int	i;

	i = 0;
	while (game->map && game->map[i])
	{
		free(game->map[i]);
		i++;
	}
}
