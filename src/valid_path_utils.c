/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachhoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:12:10 by aachhoub          #+#    #+#             */
/*   Updated: 2022/12/28 15:26:42 by aachhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	**get_map(char *path, t_game *game)
{
	int		fd;
	char	*s;
	int		len;
	char	**map;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		message_destroy(RED"Error: Couldn't open the map!"RESET, 2, game);
	s = ft_calloc(1, 10000);
	if (!s)
		message_destroy(RED"Error: Allocation Failed!"RESET, 2, game);
	len = read(fd, s, 9999);
	if (len <= 0)
		message_destroy(RED"Error: Couldn't read map!"RESET, 2, game);
	map = ft_split(s, '\n');
	if (!map)
		message_destroy(RED"Error: ft_split!"RESET, 2, game);
	free(s);
	return (map);
}

int	chrcmp(char *c1, char c2)
{
	int	i;

	i = 0;
	while (c1[i])
	{
		if (c1[i] == c2)
			return (0);
		i++;
	}
	return (1);
}
