/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserrao- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:47:59 by vserrao-          #+#    #+#             */
/*   Updated: 2022/06/15 12:48:15 by vserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int argc, char **argv)
{
	t_sizes	sizes;

	if (argc != 2)
		return (0);
	if (!check_map(argv[1], map()))
		error_and_exit(); // FREE MAP ??
	sizes = sizes_struct(argv[1]);
	set_start_pos(sizes.size_x / 64, sizes.size_y / 64);
	(*mlx_struct()).mlx = mlx_init();
	if (!(*mlx_struct()).mlx)
		error_and_exit(); //FREE MAP
	(*mlx_struct()).window = mlx_new_window((*mlx_struct()).mlx, \
			sizes.size_x, sizes.size_y, "So Long!");
	put_images(64);
	count_colectibles(sizes.size_x / 64, sizes.size_y / 64);
	put_window((*mlx_struct()).mlx, (*mlx_struct()).window, sizes.size_x / 64, sizes.size_y / 64);
	mlx_hook((*mlx_struct()).window, 17, 0, ft_exit_game, &sizes);
	mlx_key_hook((*mlx_struct()).window, key_hook, &sizes);
	mlx_loop((*mlx_struct()).mlx);
	ft_exit_game(&sizes);
}

void	error_and_exit(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

void	print_moves(void)
{
	write(1, "Number of moves: ", 17);
	ft_putnbr_fd((*mlx_struct()).nbr_of_moves, 1);
	write(1, "\n", 1);
}
