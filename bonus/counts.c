/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachhoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:59:37 by aachhoub          #+#    #+#             */
/*   Updated: 2022/12/29 16:01:27 by aachhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	clear_text(t_game *game)
{
	t_image	image;
	size_t	i;

	image.path = "./res/bg.xpm";
	image.game = *game;
	i = 0;
	while (i <= game -> x)
	{
		put_image(image, i, game -> y);
		i += SIZE;
	}
}

void	display_count(t_game *game, int count, int bonus)
{
	char	*s;
	char	*temp1;
	char	*temp2;

	clear_text(game);
	s = ft_strjoin("Moves count = ", ft_itoa(count));
	mlx_string_put(game -> mlx, game -> win,
		game -> x / 3, game -> y + 12, 0, s);
	free(s);
	temp1 = ft_strjoin("Collectibles = ", ft_itoa(bonus));
	temp2 = ft_strjoin(temp1, " / ");
	s = ft_strjoin(temp2, ft_itoa(game -> check_coin));
	free(temp1);
	free(temp2);
	if (bonus == game -> check_coin)
		mlx_string_put(game -> mlx, game -> win,
			(game -> x / 3) * 2, game -> y + 12, 5754009, s);
	else
		mlx_string_put(game -> mlx, game -> win,
			(game -> x / 3) * 2, game -> y + 12, 15672124, s);
	free(s);
}
