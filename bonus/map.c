/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachhoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:10:21 by aachhoub          #+#    #+#             */
/*   Updated: 2022/12/28 15:10:22 by aachhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	free(game->map);
}

void	create_map(t_game *game, int i)
{
	int		j;
	t_block	block;
	t_image	image;

	image.game = *game;
	j = 0;
	while (game->map[i])
	{
		while (game->map[i][j])
		{
			block = set_block(game->map[i][j]);
			if (game->map[i][j] == 'E')
			{
				game -> exit_coordinates[0] = (j * SIZE);
				game -> exit_coordinates[1] = (i * SIZE);
			}
			image.path = block.path;
			put_image(image, (j * SIZE), (i * SIZE));
			j++;
		}
		i++;
	}
}

void	create_floor(t_game game, int b)
{
	int		j;
	t_image	image;

	image.game = game;
	j = 0;
	if (ft_strlen(game.map[b]) != game.x / SIZE && b != (game.y / SIZE))
		message_destroy(RED"Error:\nThe map is not rectangular\n"RESET, 2, &game);
	if (game.map[(game.y / SIZE)] && game.map[(game.y / SIZE)][0] != '\0')
		message_destroy(RED"Error:\nInvalid map\n"RESET, 2, &game);
	while (game.map[b])
	{
		j = 0;
		while (game.map[b][j])
		{
			if (!(ft_strchr("1PCE0H", game.map[b][j])))
				message_destroy(RED"Error:\nUknown element\n"RESET, 2, &game);
			image.path = "./res/floor.xpm";
			put_image(image, (j * SIZE), (b * SIZE));
			j++;
		}
		b++;
	}
}

void	create_map_len(char *area, t_game *game, int i)
{
	int		j;
	t_image	image;

	image.game = *game;
	j = 0;
	game->map[i] = (char *)malloc(sizeof(char) * (9999));
	while (area[j] && area[j] != '\n')
	{
		game->map[i][j] = area[j];
		j++;
	}
	game->map[i][j] = '\0';
	create_floor(*game, i);
	create_map(game, i);
}

void	create_map_line(t_game *game, char **av)
{
	int		fd;
	char	*area;
	int		i;

	game->map = (char **)malloc(sizeof(char *) * (9999));
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		message_destroy(RED"Error: File not found!"RESET, 1, game);
	i = 0;
	while (i <= game -> y / SIZE)
	{
		area = get_next_line(fd);
		if (area == NULL)
			break ;
		create_map_len(area, game, i);
		i++;
	}
	close(fd);
}
