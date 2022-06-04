#include "../inc/so_long.h"

int	main(int argc, char **argv)
{
	int		size_x;
	int		size_y;

	if (argc != 2)
		return (0);
	if (!check_map(argv[1], map()))
		write(1, "Error\n", 6);
	size_y = map_size_y(argv[1]);
	size_x = map_size_x(argv[1]);
	set_start_pos();
	(*mlx_struct()).mlx = mlx_init();
	if (!(*mlx_struct()).mlx)
		return (0); //Check
	(*mlx_struct()).window = mlx_new_window((*mlx_struct()).mlx, size_x, size_y, "So Long!");
}