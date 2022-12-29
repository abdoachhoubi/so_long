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

	blocks[0] = (t_block){"1", "./res/wall.xpm"};
	blocks[1] = (t_block){"0", "./res/floor.xpm"};
	blocks[2] = (t_block){"C", "./res/coin.xpm"};
	blocks[3] = (t_block){"P", "./res/hero.xpm"};
	blocks[4] = (t_block){"E", "./res/exit.xpm"};
	blocks[5] = (t_block){NULL, NULL};
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
	return (blocks[5]);
}
