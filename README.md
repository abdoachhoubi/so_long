# So Long

## Table of content

1. [Description](#description)

2. [Functions](#functions)

3. [Macros](#macros)

4. [Structs](#structs)

## Description

This project is a very small 2D game in C.
Its purpose is to make you work with textures, sprites, and some other very basic gameplay elements.

```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachhoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:04:06 by aachhoub          #+#    #+#             */
/*   Updated: 2022/12/28 15:04:06 by aachhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
```

## Functions

### Mandatory:

- [x] message_exit: Prints a message, and exits the program.
- [x] win_size: Counts the window size.
- [x] line_length: Counts the length of a line in the map.
- [x] lines_count: Counts the number of lines in the map.
- [x] initialize: Initializes all checks with 0.
- [x] create_map_line: Stores the map from the file into a 2D array.
- [x] message_destroy: Prints a message, destroys the map and exits the program.
- [x] destroy_map: Frees the 2D array.
- [x] create_map_len: Stores each line of the map in an index of the 2D array.
- [x] create_floor: Checks the basic map validations, and put the floor in the window.
- [x] put_image: Puts an image into a specific position in the window.
- [x] create_map: Puts all images in their places in the map.
- [x] set_block: Returns an image path depending on it's character in the 2D array.
- [x] game_controller: Perform some validations on the map.
- [x] map_controller: Perform basic map checks.
- [x] wall_controller: Checks if the map is surrounded by walls.
- [x] valid_path: Checks if the path is valid or not.
- [x] get_map: Parses the map into a 2D array.
- [x] flood_fill: Takes a position in the map and fills its surroundings with a specific charater.
- [x] chrcmp: Checks if a string contains a specific character.
- [x] check_coins: Counts the coins in the map.
- [x] valid_exit: Validates the exit.
- [x] check_exit: Checks if any of the exit surroundings is equal to the character used in flood_fill.
- [x] key_pressed: A callback function that handles the user interaction with the game using the keyboard.
- [x] up: Handles a move towards UP.
- [x] move_check: Handles the outcome of a move.
- [x] open_exit: Opens the exit if all coins are collected.
- [x] update: Replaces the current position with floor.
- [x] right: Handles a move towards RIGHT.
- [x] down: Handles a move towards DOWN.
- [x] left: Handles a move towards LEFT.

### Bonus:

- [x] clear_text: Clears the Moves and Collectibles counts.
- [x] display_count: Displays the count of Moves and Collectibles.

## Macros

```c
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
```

## Structs

```c
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
```
