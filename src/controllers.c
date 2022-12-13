#include "../inc/so_long.h"

// Updates the map
void	update(t_game *game, int x, int y)
{
	t_image	image;

	image.path = "./res/floor.xpm";
	image.game = *game;
	put_image(image, game->player.x, game->player.y);
	put_image(image, x, y);
}

void	right(t_game *game)
{
	int		i;
	int		j;
	t_image	image;

	image.path = "./res/player.xpm";
	image.game = *game;
	i = game->player.y;
	j = game->player.x + 48;
	if ((move_check(game, (i / 48), (j / 48)) != 1))
	{
		game->player.move++;
		ft_printf(GREEN"Moves count = %d\n"RESET, game->player.move);
		update(game, j, i);
		game->player.y = i;
		game->player.x = j;
		put_image(image, j, i);
	}
}

void	left(t_game *game)
{
	int		i;
	int		j;
	t_image	image;

	image.path = "./res/left.xpm";
	image.game = *game;
	i = game->player.y;
	j = game->player.x - 48;
	if ((move_check(game, (i / 48), (j / 48)) != 1))
	{
		game->player.move++;
		ft_printf(GREEN"moves count = %d\n"RESET, game->player.move);
		update(game, j, i);
		game->player.y = i;
		game->player.x = j;
		put_image(image, j, i);
	}
}

void	up(t_game *game)
{
	int		i;
	int		j;
	t_image	image;

	image.path = "./res/player.xpm";
	image.game = *game;
	i = game->player.y - 48;
	j = game->player.x;
	if ((move_check(game, (i / 48), (j / 48)) != 1))
	{
		game->player.move++;
		ft_printf(GREEN"moves count = %d\n"RESET, game->player.move);
		update(game, j, i);
		game->player.y = i;
		game->player.x = j;
		put_image(image, j, i);
	}
}

void	down(t_game *game)
{
	int		i;
	int		j;
	t_image	image;

	image.path = "./res/player.xpm";
	image.game = *game;
	i = game->player.y + 48;
	j = game->player.x;
	if ((move_check(game, (i / 48), (j / 48)) != 1))
	{
		game->player.move++;
		ft_printf(GREEN"moves count = %d\n"RESET, game->player.move);
		update(game, j, i);
		game->player.y = i;
		game->player.x = j;
		put_image(image, j, i);
	}
}
