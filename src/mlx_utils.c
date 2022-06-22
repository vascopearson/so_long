/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserrao- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:52:17 by vserrao-          #+#    #+#             */
/*   Updated: 2022/06/22 12:39:19 by vserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_mlx	*mlx_struct(void)
{
	static t_mlx	return_mlx_struct;

	return (&return_mlx_struct);
}

int	key_hook(int keycode, t_sizes *sizes)
{
	if (keycode == 53)
		ft_exit_game(sizes);
	if (keycode == 0)
		ft_move(-1, 0, sizes);
	if (keycode == 1)
		ft_move(0, 1, sizes);
	if (keycode == 2)
		ft_move(1, 0, sizes);
	if (keycode == 13)
		ft_move(0, -1, sizes);
	mlx_clear_window((*mlx_struct()).mlx, (*mlx_struct()).window);
	put_window((*mlx_struct()).mlx, (*mlx_struct()).window, \
			sizes->size_x / 64, sizes->size_y / 64);
	return (0);
}

void	ft_move(int x_step, int y_step, t_sizes *sizes)
{
	int	x;
	int	y;

	y = 0;
	while (y < sizes->size_y / 64)
	{
		x = 0;
		while (x < sizes->size_x / 64)
		{
			if ((*map())[y][x] == 'P' && \
					(*map())[y + y_step][x + x_step] != '1')
			{
				if (ft_move_consequence(x + x_step, y + y_step, \
							sizes->size_y / 64) == 1)
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

int	ft_move_consequence(int x, int y, int size_y)
{
	if ((*map())[y][x] == 'C')
		(*mlx_struct()).colectibles--;
	if ((*map())[y][x] == 'E')
	{
		if ((*mlx_struct()).colectibles == 0)
		{
			(*mlx_struct()).nbr_of_moves++;
			print_moves();
			free_map(map(), size_y);
			exit(0);
		}
		else
			return (1);
	}
	return (0);
}
