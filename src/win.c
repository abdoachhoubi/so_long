#include "../inc/so_long.h"

int	destroy_win(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	message(YELLOW"Game closed\n"RESET, 1, game);
	destroy_map(game);
	exit(0);
}

void	win_size(t_game *game, char **av)
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		message(RED"Error:\nFile not found\n"RESET, 2, game);
	if (ft_strnstr(av[1], ".ber", ft_strlen(av[1])) == NULL)
		message(RED"Error:\nYour map does not have a .ber extension\n"RESET, 2, game);
	game->x = (line_length(fd) * 48);
	game->y = lines_count(fd) * 48;
    // DEBUG
    printf("line_height: %zu\n", game->x);
    printf("lines_count: %d\n", game->y);
}