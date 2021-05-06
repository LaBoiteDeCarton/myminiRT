#include "minirt.h"

int start_rt(t_scene *scene)
{
	void *mlx_ptr;
	void *mlx_win;

	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (0);
	mlx_win = mlx_new_window(mlx_ptr, scene->resolution.x, scene->resolution.y, "MiniRT - Ray Tracing project");
	put_scene(mlx_ptr, mlx_win, scene);
	if (!mlx_win)
		return (0);	
	mlx_loop(mlx_ptr);
	return (1);
}