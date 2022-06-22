/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserrao- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 13:00:20 by vserrao-          #+#    #+#             */
/*   Updated: 2022/06/22 12:38:51 by vserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	check_name(char *map_file)
{
	int	i;

	i = ft_strlen(map_file);
	if (i > 3 && map_file[i - 1] == 'r' && map_file[i - 2] == 'e' && \
			map_file[i - 3] == 'b' && map_file[i - 4] == '.')
		return (1);
	return (0);
}

int	map_content(char **str, int size_y)
{
	int	k;
	int	i;
	int	j;

	k = 0;
	i = 0;
	while (i < size_y)
	{
		j = 0;
		while (str[i][j] && str[i][j] != '\n' && \
		str[i][j] && str[i][j] != '\0')
		{
			if (!check_valid(str[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	if (!check_at_least_one(str, size_y))
		return (0);
	return (1);
}

int	check_valid(char c)
{
	if (c == '1' || c == '0' || c == 'P' || c == 'C' || c == 'E')
		return (1);
	return (0);
}

int	check_at_least_one(char **str, int size_y)
{
	if (!check_object(str, 'P', size_y))
		return (0);
	if (!check_object(str, 'C', size_y))
		return (0);
	if (!check_object(str, 'E', size_y))
		return (0);
	return (1);
}

int	check_object(char **str, char c, int size_y)
{
	int	i;
	int	j;

	i = 0;
	while (i < size_y)
	{
		j = 0;
		while (str[i][j] && str[i][j] != '\n')
		{
			if (str[i][j] == c)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
