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
# define YELLOW	"\033[1m\033[32m"
# define RESET	"\033[0m"

// Keyboard keys codes
# define UP		13
# define RIGHT	2
# define DOWN	1
# define LEFT	0
# define ESC	53

// Size
# define SIZE	42

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
	int			check_coin;
	int			check_player;
	int			check_exit;
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
void	message(char *msg, int fd, t_game *game);
int		line_length(int fd);
int		lines_count(int fd);

#endif