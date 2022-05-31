#include "../inc/so_long.h"


typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	render_next_frame(t_vars *strct)
{
	strct->mlx = mlx_init();
	mlx_loop_hook(strct->mlx, render_next_frame, strct);
	mlx_loop(strct->mlx);
	return (0);
}

int	main(void)
{
	t_vars	*strct = NULL;

	strct->mlx = mlx_init();
	mlx_loop_hook(strct->mlx, render_next_frame, strct);
	mlx_loop(strct->mlx);
}
