#include "../inc/so_long.h"

void	initialize(t_game *game)
{
	game->check_coin = 0;
	game->check_exit = 0;
	game->player.coin = 0;
	game->player.move = 0;
	game->check_player = 0;
}

void	create_map(t_game *game, int i)
{
	int		j;
	t_block	map;
	t_image	image;

	image.game = *game;
	j = 0;
	while (game->map[i])
	{
		while (game->map[i][j])
		{
			map = set_block(game->map[i][j]);
			image.path = map.path;
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
	// DEBUG
	printf("i = %d\tj = %d\tmap item = %c\n\n", b, j, game.map[1][j]);
	if (ft_strlen(game.map[b]) != game.x / 48 && b != (game.y / 48))
		message(RED"Error:\nThe map is not rectangular\n"RESET, 2, &game);
	if (game.map[(game.y / 48)] && game.map[(game.y / 48)][0] != '\0')
		message(RED"Error:\nInvalid map\n"RESET, 2, &game);
	while (game.map[b])
	{
		j = 0;
		while (game.map[b][j])
		{
			// DEBUG
			printf("i = %d\tj = %d\tmap item = %c\n\n", b, j, game.map[b][j]);
			if (!(ft_strchr("1PCE0", game.map[b][j])))
				message(RED"Error:\nUknown element\n"RESET, 2, &game);
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
	while (area[j])
	{
		if (area[j] == '\n')
			break ;
		game->map[i][j] = area[j];
		j++;
	}
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
	i = 0;
	while (i <= game->y / 48)
	{
		area = get_next_line(fd);
		if (area == NULL)
			break ;
		create_map_len(area, game, i);
		i++;
	}
	close(fd);
}
