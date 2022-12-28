#include "../inc/so_long.h"

int enemies_count(t_game *game)
{
    int i;
    int j;
    int count;

    i = 0;
    count = 0;
    while (game -> map[i])
    {
        j = 0;
        while (game -> map[i][j])
        {
            if (game -> map[i][j] == 'H')
                count++;
            j++;
        }
        i++;
    }
    return (count);
}

int	enemy_move_check(t_game *game, int i, int j)
{
	if (game->map[i][j] == '1')
		return (1);
    if (game->map[i][j] == 'C')
        return (1);
    if (game->map[i][j] == 'E')
        return (1);
	return (0);
}

void    update_enemy(t_game *game, t_image image, int i, int j, int x)
{
    update(game, j, i);
	game->enemies[x].y = i;
	game->enemies[x].x = j;
	put_image(image, j, i);
}

void    move_enemie(t_game *game, t_image image, int x)
{
    int i;
    int j;

    sleep(1);
    i = game->enemies[x].y;
	j = game->enemies[x].x + SIZE;
	if ((enemy_move_check(game, (i / SIZE), (j / SIZE)) != 1))
        update_enemy(game, image, i, j, x);
    else
    {
        i = game->enemies[x].y;
        j = game->enemies[x].x - SIZE;
        if ((enemy_move_check(game, (i / SIZE), (j / SIZE)) != 1))
            update_enemy(game, image, i, j, x);
        else
        {
            i = game->enemies[x].y + SIZE;
            j = game->enemies[x].x;
            if ((enemy_move_check(game, (i / SIZE), (j / SIZE)) != 1))
                update_enemy(game, image, i, j, x);
            else
            {
                i = game->enemies[x].y - SIZE;
                j = game->enemies[x].x;
                if ((enemy_move_check(game, (i / SIZE), (j / SIZE)) != 1))
                    update_enemy(game, image, i, j, x);
            }
        }
    }
}

void    move_enemies(t_game *game)
{
	t_image	image;
    int     i;

	image.path = "./res/left.xpm";
	image.game = *game;
    while (1)
    {
        i = 0;
        while (i < game -> e_count)
        {
            move_enemie(game, image, i);
            i++;
        }
    }
}

void    enemies(t_game  *game)
{
    int e_count;
    int i;
    int j;
    int b;

    e_count = enemies_count(game);
    game -> e_count = e_count;
    game -> enemies = (t_enemy *)malloc((e_count) * sizeof(t_enemy));
    if (!game -> enemies)
        message_destroy(RED"Error:\nMalloc Error"RESET, 2, game);
    i = 0;
    b = 0;
    while (game -> map[i])
    {
        j = 0;
        while (game -> map[i][j])
        {
            if (game -> map[i][j] == 'H')
            {
                game -> enemies[b].x = j;
                game -> enemies[b].y = i;
                game -> enemies[b].x_map = j * 48;
                game -> enemies[b].y_map = i * 48;
                b++;
            }
            j++;
        }
        i++;
    }
}