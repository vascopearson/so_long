#include "../inc/so_long.h"

int map_rectangular(char **str)
{
    int i;

    i = 1;
    while (str[i])
    {
        if (ft_xlen(str[i]) != ft_xlen(str[i - 1]))
            return (0);
        i++;
    }
    return (1);
}

int ft_xlen(char *str)
{
    int len;

    len = 0;
    while (str[len] && str[len] != '\n')
        len++;
    return (len);
}

int map_closed(char **str)
{
    int i;
    int j;

    if (!map_rectangular(str))
        return (0);
    i = 0;
    j = ft_xlen(str[0]) - 1;
    while (str[i] && str[i][j])
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

void    set_start_pos(void)
{
    int x;
    int y;
    int counter;

    x = 0;
    counter = 0;
    while ((*map())[x])
    {
        y = 0;
        while ((*map())[x][y])
        {
            if ((*map())[x][y] == 'P')
            {
                counter++;
                if (counter > 1)
                    (*map())[x][y] = '0';
            }
            y++;
        }
        x++;
    }
}