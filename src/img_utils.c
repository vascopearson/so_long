#include "../inc/so_long.h"

t_images    *images(void)
{
    static t_images image;

    return (&image);
}

void    put_images(int size)
{
    (*images()).dolphin = mlx_xpm_file_to_image((*mlx_struct()).mlx, "./images/Dolphin.xpm", &size, &size);
    (*images()).fish = mlx_xpm_file_to_image((*mlx_struct()).mlx, "./images/Fish.xpm", &size, &size);
    (*images()).water = mlx_xpm_file_to_image((*mlx_struct()).mlx, "./images/Water.xpm", &size, &size);
    (*images()).algae = mlx_xpm_file_to_image((*mlx_struct()).mlx, "./images/Algae.xpm", &size, &size);
    (*images()).door = mlx_xpm_file_to_image((*mlx_struct()).mlx, "./images/Door.xpm", &size, &size);
}

void    put_window(void *mlx, void *window)
{
    int x;
    int y;

    y = 0;
    while ((*map())[y])
    {
        x = 0;
        while ((*map())[y][x])
        {
            put_object(x, y, mlx, window);
            x++;
        }
        y++;
    }
}

void    put_object(int x, int y, void *mlx, void *window)
{
    if ((*map())[y][x] == '1')
        mlx_put_image_to_window(mlx, window, (*images()).algae, x * 64, y * 64);
    if ((*map())[y][x] == '0')
        mlx_put_image_to_window(mlx, window, (*images()).water, x * 64, y * 64);
    if ((*map())[y][x] == 'P')
        mlx_put_image_to_window(mlx, window, (*images()).dolphin, x * 64, y * 64);
    if ((*map())[y][x] == 'C')
        mlx_put_image_to_window(mlx, window, (*images()).fish, x * 64, y * 64);
    if ((*map())[y][x] == 'E')
        mlx_put_image_to_window(mlx, window, (*images()).door, x * 64, y * 64);
}