#include "../inc/so_long.h"

t_mlx   *mlx_struct(void)
{
    static t_mlx   return_mlx_struct;

    return (&return_mlx_struct);
}

int key_hook(int keycode)
{
    if (keycode == 53) //esc
        ft_exit_game();
    if (keycode == 0) //left
        ft_move(-1, 0);
    if (keycode == 1) //down
        ft_move(0, -1);
    if (keycode == 2) //right
        ft_move(1, 0);
    if (keycode == 13) //up
        ft_move(0, 1);
    mlx_clear_window((*mlx_struct()).mlx, (*mlx_struct()).window);
    put_window((*mlx_struct()).mlx, (*mlx_struct()).window);
    return (0);
}

void    ft_move(int x_step,int y_step)
{
    int x;
    int y;

    y = 0;
    while ((*map())[y])
    {
        x = 0;
        while ((*map())[y][x])
        {
            
        }
        
    }
}