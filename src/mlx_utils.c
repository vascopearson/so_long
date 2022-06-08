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
        ft_move(0, 1);
    if (keycode == 2) //right
        ft_move(1, 0);
    if (keycode == 13) //up
        ft_move(0, -1);
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
            if ((*map())[y][x] == 'P' && (*map())[y + y_step][x + x_step] != '1')
            {
                if (ft_move_consequence(x, y, x_step, y_step) == 1)
                    return ;
                (*map())[y][x] = '0';
                (*map())[y + y_step][x + x_step] = 'P';
                (*mlx_struct()).nbr_of_moves++;
                print_moves();
                return ;
            }
            x++;
        }
        y++;
    }
}

int    ft_move_consequence(int x, int y, int x_step, int y_step)
{
    if ((*map())[y + y_step][x + x_step] == 'C')
        (*mlx_struct()).colectibles--;
    if ((*map())[y + y_step][x + x_step] == 'E')
    {
        if ((*mlx_struct()).colectibles == 0)
        {
            free_map(map());
            exit(0);
        }
        else
            return (1);
    }
    return (0);
}