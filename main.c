#include "mlx.h"

int main()
{
    int j;
    int y = 0;
    int x = 0;

    void *mlx = mlx_init();
	void *win = mlx_new_window(mlx, 1080, 720, "Astro");
    void *img = mlx_xpm_file_to_image(mlx,
			"./res/wall.xpm", &x, &y);
    
    int i = 0;
    while (i < 10)
    {
        j = 0;
        y = 0;
        while (j < 6)
        {
	        mlx_put_image_to_window(mlx, win, img, x, y);
            y += 40;
            j++;
        }
        x += 40;
        i++;
    }
    mlx_loop(mlx);
}
