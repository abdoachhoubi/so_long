/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachhoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:27:12 by aachhoub          #+#    #+#             */
/*   Updated: 2022/12/28 15:27:22 by aachhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// Puts an image in the window
void	*put_image(t_game *game, t_image image, int x, int y)
{
	char	*s;

	s = "Error:\n Couldn't open mlx file -_-";
	image.img = mlx_xpm_file_to_image(image.game.mlx,
			image.path, &image.width, &image.height);
	if (! image.img)
		message_destroy(s, 2, game);
	mlx_put_image_to_window(image.game.mlx, image.game.win, image.img, x, y);
	return (image.img);
}

// Sets an image to a specific block
t_block	set_block(char name)
{
	t_block	blocks[7];
	int		i;

	blocks[0] = (t_block){"1", "./textures/wall.xpm"};
	blocks[1] = (t_block){"0", "./textures/floor.xpm"};
	blocks[2] = (t_block){"C", "./textures/coin.xpm"};
	blocks[3] = (t_block){"P", "./textures/hero.xpm"};
	blocks[4] = (t_block){"H", "./textures/player.xpm"};
	blocks[5] = (t_block){"E", "./textures/exit.xpm"};
	blocks[6] = (t_block){NULL, NULL};
	i = 0;
	while (blocks[i].name)
	{
		if (blocks[i].name[0] == name)
		{
			return (blocks[i]);
			break ;
		}
		i++;
	}
	return (blocks[6]);
}
