/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sizes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserrao- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 17:27:08 by vserrao-          #+#    #+#             */
/*   Updated: 2022/06/22 12:39:32 by vserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_sizes	sizes_struct(char *map_file)
{
	t_sizes	return_sizes_struct;

	return_sizes_struct.size_x = map_size_x(map_file) * 64;
	return_sizes_struct.size_y = map_size_y(map_file) * 64;
	return (return_sizes_struct);
}
