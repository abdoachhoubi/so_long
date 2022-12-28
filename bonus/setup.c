/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachhoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:27:37 by aachhoub          #+#    #+#             */
/*   Updated: 2022/12/28 15:27:40 by aachhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	initialize(t_game *game)
{
	game->check_coin = 0;
	game->check_exit = 0;
	game->player.coin = 0;
	game->player.move = 0;
	game->check_player = 0;
}
