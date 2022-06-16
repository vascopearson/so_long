/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserrao- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 13:16:06 by vserrao-          #+#    #+#             */
/*   Updated: 2022/06/15 13:19:35 by vserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../get_next_line/get_next_line.h"
# include <mlx.h>
# include <libft.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_images {
	void	*dolphin;
	void	*fish;
	void	*water;
	void	*door;
	void	*algae;
}	t_images;

typedef struct s_mlx {
	void	*mlx;
	void	*window;
	int		colectibles;
	int		nbr_of_moves;
}	t_mlx;

typedef struct s_sizes {
	int	size_x;
	int	size_y;
}	t_sizes;

char		***map(void);
int			map_size_x(char *map_file);
int			map_size_y(char *map_file);
t_sizes		sizes_struct(char *map_file);
int			check_map(char *map_file, char ***map);
int			check_name(char *map_file);
int			map_content(char **str, int size_y);
int			check_valid(char c);
int			check_at_least_one(char **str, int size_y);
int			check_object(char **str, char c, int size_y);
int			map_rectangular(char **str, int size_y);
int			map_closed(char **str, int size_y);
int			ft_xlen(char *str);
void		free_map(char ***str_map, int size_y);
void		set_start_pos(int size_x, int size_y);
void		count_colectibles(int size_x, int size_y);

t_mlx		*mlx_struct(void);
int			key_hook(int keycode, t_sizes *sizes);
void		ft_move(int x_step, int y_step, t_sizes *sizes);
int			ft_move_consequence(int x, int y, int size_y);

t_images	*images(void);
void		put_images(int size);
void		put_window(void *mlx, void *window, int size_x, int size_y);
void		put_object(int x, int y, void *mlx, void *window);
void		destroy_images(void);

int			ft_exit_game(t_sizes *sizes);
void		error_and_exit(void);
void		free_error_and_exit(char ***str_map, int size_y);
void		print_moves(void);

#endif
