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
	int		size_x;
	int		size_y;

	if (argc != 2)
		return (0);
	if (!check_map(argv[1], map()))
		error_and_exit();
	size_y = map_size_y(argv[1]) * 64;
	size_x = map_size_x(argv[1]) * 64;
	set_start_pos();
	(*mlx_struct()).mlx = mlx_init();
	if (!(*mlx_struct()).mlx)
		error_and_exit();
	(*mlx_struct()).window = mlx_new_window((*mlx_struct()).mlx, \
			size_x, size_y, "So Long!");
	put_images(64);
	count_colectibles();
	put_window((*mlx_struct()).mlx, (*mlx_struct()).window);
	mlx_hook((*mlx_struct()).window, 17, 0, ft_exit_game, 0);
	mlx_key_hook((*mlx_struct()).window, key_hook, 0);
	mlx_loop((*mlx_struct()).mlx);
	ft_exit_game();
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
