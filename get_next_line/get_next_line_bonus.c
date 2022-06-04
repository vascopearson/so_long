/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserrao- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:26:37 by vserrao-          #+#    #+#             */
/*   Updated: 2021/11/22 14:26:40 by vserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_line(char **save)
{
	char		*line;
	char		*temp;
	int			n;

	if (!*save || !**save)
		return (NULL);
	n = (int)((ft_strchr(*save, '\n')) - *save);
	if (ft_strchr(*save, '\n'))
	{
		line = ft_substr(*save, 0, n + 1);
		temp = ft_substr(*save, n + 1, ft_strlen(*save));
		free (*save);
		*save = temp;
		if (**save != '\0')
			return (line);
	}
	else
		line = ft_strdup(*save);
	free (*save);
	*save = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	char		*temp;
	char		*buffer;
	static char	*save[FD_MAX];
	int			ret;

	if (fd < 0 || BUFFER_SIZE < 1 || fd > FD_MAX)
		return (NULL);
	buffer = (char *)malloc((1 + BUFFER_SIZE) * sizeof(char));
	if (!buffer)
		return (NULL);
	ret = read(fd, buffer, BUFFER_SIZE);
	while (ret > 0)
	{
		buffer[ret] = '\0';
		if (save[fd] == NULL)
			save[fd] = ft_strdup("");
		temp = ft_strjoin(save[fd], buffer);
		free (save[fd]);
		save[fd] = temp;
		if (ft_strchr(save[fd], '\n'))
			break ;
		ret = read(fd, buffer, BUFFER_SIZE);
	}
	free (buffer);
	return (ft_line(&save[fd]));
}
