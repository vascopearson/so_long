#ifndef SOLONG_H
# define SOLONG_H

# include "../get_next_line/get_next_line.h"
# include <mlx.h>
# include <libft.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

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


#endif
