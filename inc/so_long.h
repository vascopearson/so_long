#ifndef SOLONG_H
# define SOLONG_H

# include "../get_next_line/get_next_line.h"
# include <mlx.h>
# include <libft.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_images {
    void    *dolphin;
    void    *fish;
    void    *water;
    void    *door;
    void    *algae;
}   t_images;

typedef struct s_mlx {
    void    *mlx;
    void    *window;
    int     colectibles;
    int     nbr_of_moves;
}   t_mlx;

char    ***map(void);
int     map_size_x(char *map_file);
int     map_size_y(char *map_file);
int     check_map(char *map_file, char ***map);
int     check_name(char *map_file);
int     map_content(char **str);
int     check_valid(char c);
int     check_at_least_one(char **str);
int     check_object(char **str, char c);
int     map_rectangular(char **str);
int     map_closed(char **str);
int     ft_xlen(char *str);
void    free_map(char ***str_map);
void    set_start_pos(void);
void    count_colectibles(void);

t_mlx   *mlx_struct(void);
int     key_hook(int keycode);
void    ft_move(int x_step,int y_step);
int    ft_move_consequence(int x, int y, int x_step, int y_step);

t_images    *images(void);
void    put_images(int size);
void    put_window(void *mlx, void *window);
void    put_object(int x, int y, void *mlx, void *window);
void    destroy_images(void);

int     ft_exit_game(void);
void	error_and_exit(void);
void	print_moves(void);

#endif
