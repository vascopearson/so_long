/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserrao- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 13:09:41 by vserrao-          #+#    #+#             */
/*   Updated: 2022/06/15 13:15:57 by vserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	***map(void)
{
	static char	**map;

	return (&map);
}

int	map_size_x(char *map_file)
{
	char	buffer[1];
	int		fd;
	int		size;

	size = 0;
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		return (0);
	while (read(fd, buffer, 1))
	{
		if (buffer[0] == '\n' || buffer[0] == '\0')
			break ;
		size++;
	}
	close(fd);
	return (size);
}

int	map_size_y(char *map_file)
{
	char	buffer[1];
	int		fd;
	int		size;

	size = 0;
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		return (0);
	while (read(fd, buffer, 1))
	{
		if (buffer[0] == '\n' || buffer[0] == '\0')
			size++;
	}
	if (buffer[0] != '\n' && buffer[0] != '\0')
		size++;
	close(fd);
	
	return (size);
}

int	check_map(char *map_file, char ***str_map)
{
	int		size_y;
	int		i;
	int		fd;

	if (!check_name(map_file))
		return (0);
	size_y = map_size_y(map_file);
	(*str_map) = malloc(sizeof(char *) * size_y);
	if (!(*str_map))
		error_and_exit();
	i = 0;
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		return (0);
	(*str_map)[i++] = get_next_line(fd);
	while (i < size_y)
		(*str_map)[i++] = get_next_line(fd);
	if (!map_content((*str_map), size_y) || \
			!map_rectangular((*str_map), size_y) || !map_closed((*str_map), size_y))
	{
		free_map(str_map, size_y);
		return (0);
	}
	return (1);
}

void	free_map(char ***str_map, int size_y)
{
	int	i;

	i = 0;
	while (i < size_y)
	{
		free((*str_map)[i]);
		i++;
	}
	free(*str_map);
}
