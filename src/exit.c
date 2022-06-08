#include "../inc/so_long.h"

int     ft_exit_game(void)
{
    destroy_images();
    free_map(map());
    exit(0);
    return (0);
}