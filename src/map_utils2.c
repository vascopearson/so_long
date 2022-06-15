/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserrao- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:56:18 by vserrao-          #+#    #+#             */
/*   Updated: 2022/06/15 13:00:06 by vserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	map_rectangular(char **str, int size_y)
{
	int	i;

	i = 1;
	while (i < size_y)
	{
		if (ft_xlen(str[i]) != ft_xlen(str[i - 1]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_xlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	return (len);
}

int	map_closed(char **str, int size_y)
{
	int	i;
	int	j;

	if (!map_rectangular(str, size_y))
		return (0);
	i = 0;
	j = ft_xlen(str[0]) - 1;
	while (i < size_y && str[i][j])
	{
		if (str[i][0] != '1' || str[i][j] != '1')
			return (0);
		i++;
	}
	j = 0;
	i--;
	while (str[0][j] && str[i][j])
	{
		if (str[0][j] != '1' || str[i][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

void	set_start_pos(int size_x, int size_y)
{
	int	x;
	int	y;
	int	counter;

	y = 0;
	counter = 0;
	while (y < size_y)
	{
		x = 0;
		while (x < size_x)
		{
			if ((*map())[y][x] == 'P')
			{
				counter++;
				if (counter > 1)
					(*map())[y][x] = '0';
			}
			x++;
		}
		y++;
	}
}

void	count_colectibles(int size_x, int size_y)
{
	int	x;
	int	y;
	int	counter;

	counter = 0;
	y = 0;
	while (y < size_y)
	{
		x = 0;
		while (x < size_x)
		{
			if ((*map())[y][x] == 'C')
				counter++;
			x++;
		}
		y++;
	}
	(*mlx_struct()).colectibles = counter;
}
