/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachhoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:30:14 by aachhoub          #+#    #+#             */
/*   Updated: 2022/12/28 15:30:15 by aachhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>

// External libraries
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../mlx/mlx.h"

// Output text colors
# define RED	"\033[1m\033[31m"
# define GREEN	"\033[1m\033[32m"
# define YELLOW	"\033[1m\033[33m"
# define RESET	"\033[0m"

// Keyboard keys codes
# define UP1	13
# define UP2	126
# define RIGHT1	2
# define RIGHT2	124
# define DOWN1	1
# define DOWN2	125
# define LEFT1	0
# define LEFT2	123
# define ESC	53

// Size
# define SIZE	48

// Utility structs

typedef struct s_player {
	int		x;
	int		y;
	int		coin;
	int		move;
}	t_player;

typedef struct s_game {
	t_player	player;
	void		*mlx;
	void		*win;
	char		**map;
	int			e_count;
	int			check_coin;
	int			check_player;
	int			check_exit;
	int			exit_coordinates[2];
	size_t		x;
	int			y;
}	t_game;

typedef struct s_image {
	t_game	game;
	char	*path;
	void	*img;
	int		height;
	int		width;
}	t_image;

typedef struct s_block {
	char	*name;
	char	*path;
}	t_block;

// Game setup
void	initialize(t_game *game);
void	win_size(t_game *game, char **av);
void	create_map(t_game *game, int i);
void	create_floor(t_game game, int b);
void	create_map_len(char *area, t_game *game, int i);
void	create_map_line(t_game *game, char **av);
void	*put_image(t_image image, int x, int y);

// Callback functions
t_block	set_block(char name);
int		key_pressed(int code, t_game *game);
int		destroy_win(t_game *game);
void	destroy_map(t_game	*game);

// Controllers
void	wall_controller(t_game *game);
void	map_controller(t_game *gane);
void	game_controller(t_game *game);
int		move_check(t_game *game, int x, int y);
void	update(t_game *game, int x, int y);
void	up(t_game *game);
void	right(t_game *game);
void	down(t_game *game);
void	left(t_game *game);

// Utils
void	*ptr_free(void *ptr);
void	message_destroy(char *msg, int fd, t_game *game);
void	message_exit(char *msg, int fd);
int		line_length(int fd);
int		lines_count(int fd);

// Check if map is valid
int		chrcmp(char *c1, char c2);
void	flood_fill(char **map, int x, int y, int *dim);
void	print_map(char **map);
char	**get_map(char *path, t_game *game);
int		valid_path(t_game *game, char *path);
int		check_coins(char **map);

// Bonus utils
void	clear_text(t_game *game);
void	display_count(t_game *game, int count, int bonus);

#endif
