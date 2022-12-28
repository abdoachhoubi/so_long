/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachhoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:28:47 by aachhoub          #+#    #+#             */
/*   Updated: 2022/12/28 15:28:49 by aachhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// Displays a message, distroys the map, and exits the program
void	message_destroy(char *msg, int fd, t_game *game)
{
	ft_putendl_fd(msg, fd);
	destroy_map(game);
	exit(EXIT_FAILURE);
}

// Displays a message and exits the program
void	message_exit(char *msg, int fd)
{
	ft_putendl_fd(msg, fd);
	exit(EXIT_FAILURE);
}

// Counts the length of a line in the map
int	line_length(int fd)
{
	char	buff;
	int		len;
	int		bytes;

	bytes = 1;
	len = 0;
	while (bytes == 1)
	{
		bytes = read(fd, &buff, 1);
		if (buff != '\n')
			len++;
		else
			break ;
	}
	return (len);
}

// Counts the number of lines in the map
int	lines_count(int fd)
{
	int		count;
	char	*buffer;
	int		bytes;

	count = 0;
	bytes = 1;
	buffer = get_next_line(fd);
	while (buffer)
	{
		free(buffer);
		buffer = get_next_line(fd);
		count++;
	}
	count++;
	return (count);
}

void	*ptr_free(void *ptr)
{
	free(ptr);
	return (NULL);
}
