/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controllers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachhoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:05:31 by aachhoub          #+#    #+#             */
/*   Updated: 2022/12/28 15:05:36 by aachhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	clear_text(t_game *game)
{
	t_image	image;
	size_t	i;

	image.path = "./res/wall.xpm";
	image.game = *game;
	i = 0;
	while (i <= game -> x)
	{
		put_image(image, i, game -> y);
		i += SIZE;
	}
}

void	display_count(t_game *game, int count, int bonus)
{
	char	*s;

	clear_text(game);
	s = ft_strjoin("Moves count = ", ft_itoa(count));
	mlx_string_put(game -> mlx, game -> win, game -> x / 3, game -> y + 12, 16777215, s);
	free(s);
	s = ft_strjoin("Collectibles = ", ft_itoa(bonus));
	mlx_string_put(game -> mlx, game -> win, (game -> x / 3) * 2, game -> y + 12, 16777215, s);
	free(s);
}

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
	j = game->player.x + SIZE;
	if ((move_check(game, (i / SIZE), (j / SIZE)) != 1))
	{
		game->player.move++;
		display_count(game, game->player.move, game->player.coin);
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
	j = game->player.x - SIZE;
	if ((move_check(game, (i / SIZE), (j / SIZE)) != 1))
	{
		game->player.move++;
		display_count(game, game->player.move, game->player.coin);
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
	i = game->player.y - SIZE;
	j = game->player.x;
	if ((move_check(game, (i / SIZE), (j / SIZE)) != 1))
	{
		game->player.move++;
		display_count(game, game->player.move, game->player.coin);
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
	i = game->player.y + SIZE;
	j = game->player.x;
	if ((move_check(game, (i / SIZE), (j / SIZE)) != 1))
	{
		game->player.move++;
		display_count(game, game->player.move, game->player.coin);
		ft_printf(GREEN"moves count = %d\n"RESET, game->player.move);
		update(game, j, i);
		game->player.y = i;
		game->player.x = j;
		put_image(image, j, i);
	}
}
