#include "mlx.h"

int main()
{
    int x, y = 100;
    void *mlx = mlx_init();
	void *win = mlx_new_window(mlx, 1080, 720, "Astro");
    void *img = mlx_xpm_file_to_image(mlx,
			"./res/exit.xpm", &x, &y);
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_put_image_to_window(mlx, win, img, 40, 40);
    mlx_loop(mlx);
}