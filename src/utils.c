#include "../inc/so_long.h"

// Displays a messages and distroys the map
void	message(char *msg, int fd, t_game *game)
{
	ft_putendl_fd(msg, fd);
	destroy_map(game);
	exit(EXIT_FAILURE);
}

// counts the length of a line
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

int	lines_count(int fd)
{
	int		count;
	char	buffer;
	int		bytes;

	buffer = '\0';
	count = 1;
	bytes = 1;
	while (bytes == 1)
	{
		bytes = read(fd, &buffer, 1);
		if (buffer == '\n')
			count++;
	}
	return (count - 1);
}

void	*ptr_free(void *ptr)
{
	free(ptr);
	return (NULL);
}
