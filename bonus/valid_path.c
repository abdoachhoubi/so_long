/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachhoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:12:10 by aachhoub          #+#    #+#             */
/*   Updated: 2022/12/28 15:24:15 by aachhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	flood_fill(char **map, int x, int y, int *dim)
{
	if (x < 0 || x >= dim[0] || y < 0
		|| y >= dim[0] || chrcmp("PC0", map[x][y]) == 1)
		return ;
	map[x][y] = 'F';
	flood_fill(map, x + 1, y, dim);
	flood_fill(map, x - 1, y, dim);
	flood_fill(map, x, y + 1, dim);
	flood_fill(map, x, y - 1, dim);
}

int	check_coins(char **map)
{
	int	i;
	int	j;
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
		|| map[x][y + 1] == 'F' || map[x][y - 1] == 'F')
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
	int		dim[2];
	int		check;
	int		i;

	map = get_map(path, game);
	dim[0] = game -> x / SIZE;
	dim[1] = game -> y / SIZE;
	flood_fill(map, game -> player.y / SIZE, game -> player.x / SIZE, dim);
	check = check_coins(map);
	i = 0;
	if (check == 0)
		check = valid_exit(map);
	while (map[i])
		free(map[i++]);
	free(map);
	return (check);
}
