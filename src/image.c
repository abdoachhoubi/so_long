#include "../inc/so_long.h"

// Puts an image in the window
void	*put_image(t_image image, int x, int y)
{
	image.img = mlx_xpm_file_to_image(image.game.mlx,
			image.path, &image.width, &image.height);
	mlx_put_image_to_window(image.game.mlx, image.game.win, image.img, x, y);
	return (image.img);
}

// Sets an image to a specific block
t_block	set_block(char name)
{
	t_block	blocks[6];
	int		i;

	blocks[0] = (t_block){"1", "../res/player.xpm"};
	blocks[1] = (t_block){"0", "../res/floor.xpm"};
	blocks[2] = (t_block){"C", "../res/wall.xpm"};
	blocks[3] = (t_block){"P", "../res/bonus.xpm"};
	blocks[4] = (t_block){"E", "../res/exit.xpm"};
	blocks[5] = (t_block){NULL, NULL};
	i = 0;
	while (blocks[i].name != NULL)
	{
		if (blocks[i].name[0] == name)
		{
			return (blocks[i]);
			break ;
		}
		i++;
	}
	return (blocks[5]);
}