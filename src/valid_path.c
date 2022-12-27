#include "../inc/so_long.h"

void	print_map(char **map)
{
	int i;
    int j;

    i = 0;
    ft_putchar_fd('\n', 1);
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            ft_putchar_fd(map[i][j], 1);
            j++;
        }
        ft_putchar_fd('\n', 1);
        i++;
    }
}

char	**get_map(char *path, t_game *game)
{
	int		fd;
	char	*s;
	int		len;
	char	**map;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		message(RED"Error: Couldn't open the map!"RESET, 2, game);
	s = ft_calloc(1, 10000);
	if (!s)
		message(RED"Error: Allocation Failed!"RESET, 2, game);
	len = read(fd, s, 9999);
	if (len <= 0)
		message(RED"Error: Couldn't read map!"RESET, 2, game);
	map = ft_split(s, '\n');
	if (!map)
		message(RED"Error: ft_split!"RESET, 2, game);
	free(s);
	return (map);
}

int	chrcmp(char *c1, char c2)
{
	if (c1[0] != c2 && c1[1] != c2 && c1[2] != c2)
		return (1);
	else
		return (0);
}

void flood_fill(char **map, int x, int y, int height, int width)
{
    if (x < 0 || x >= width || y < 0 || y >= width || chrcmp("PC0", map[x][y]) == 1) {
        return;
    }
    map[x][y] = 'F';

    // Recursively fill the surrounding pixels with the new color
    flood_fill(map, x + 1, y, height, width);
    flood_fill(map, x - 1, y, height, width);
    flood_fill(map, x, y + 1, height, width);
    flood_fill(map, x, y - 1, height, width);
}

int	check_coins(char **map)
{
	int i;
    int j;
	int	count;

    i = 0;
	count = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
			if (map[i][j] == 'C')
				count++;
            j++;
        }
        i++;
    }
	return (count);
}

int	check_exit(char **map, int x, int y)
{
	if (map[x + 1][y] == 'F' || map[x - 1][y] == 'F'
		|| map[x][y + 1] =='F' || map[x][y - 1] == 'F')
		return (0);
	else
		return (-1);
}

int	valid_exit(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
			{
				return (check_exit(map, i, j));
			}
			j++;
		}
		i++;
	}
	return (-1);
}

int	valid_path(t_game *game, char *path)
{
	char	**map;
	int		check;
	int		i;

	map = get_map(path, game);
	flood_fill(map, game -> player.y / 48, game -> player.x / 48, game -> y / 48, game -> x / 48);
	check = check_coins(map);
	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
	if (check == 0)
		check = valid_exit(map);
	return (check);
}
