#include <mlx.h>
#include <stdlib.h>
#include "read_file.h"
#include "struct.h"

int	main(int ac, char **av)
{
	void *mlx_ptr;
	void *my_screen;
	t_scene *myscene;

	myscene = malloc(sizeof(t_scene));
	if (ac == 2)
	{
		read_file(av[1], myscene);
	}
	mlx_ptr = mlx_init();
	if (mlx_ptr)
	{
		my_screen = mlx_new_window(mlx_ptr, myscene->resolution.x, myscene->resolution.y, "première fenetre");
		if (my_screen)
		{
			mlx_loop(my_screen);
		}
	}
	free(myscene);
	return (0);
}