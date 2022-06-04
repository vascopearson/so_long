#include "../inc/so_long.h"

t_mlx   *mlx_struct(void)
{
    static t_mlx   return_mlx_struct;

    return (&return_mlx_struct);
}

