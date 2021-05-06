#include "scene.h"
#include <math.h>

#include <stdio.h> // to remove

int insideCircle(t_coord *coord, float rayon, int x, int y)
{
	double x_norm;
	double y_norm;

	x_norm = x - coord->x;
	y_norm = y - coord->y;
	return (sqrt(x_norm * x_norm + y_norm * y_norm) <= rayon);
}

int create_color(t_color obj_color)
{
	return ((char)0 << 24 | obj_color.r << 16 | obj_color.g << 8 | obj_color.b);
}

void put_scene(void *mlx_ptr, void *mlx_win, t_scene *scene)
{
	void *mlx_img;
	int bits_per_pixel;
	int line_length;
	int endian;
	char *buffer;
	int pixel;
	int color;
	int w;
	int h;

	mlx_img = mlx_new_image(mlx_ptr, 800, 600);
	buffer = mlx_get_data_addr(mlx_img, &bits_per_pixel, &line_length, &endian);
	h = 0;
	while (h < scene->resolution.y)
	{
		w = 0;
		while (w < scene->resolution.x)
		{
			if (insideCircle(((t_sphere *)((t_objet *)scene->objets->content)->obj)->position, ((t_sphere *)((t_objet *)scene->objets->content)->obj)->diam / 2, w, h))
			{
				pixel = (h * line_length) + (w * 4);
				color = 0xABCDEF;
				buffer[pixel] = color;
			}
			w++;
		}
		h++;
	}
	mlx_put_image_to_window(mlx_ptr, mlx_win, mlx_img, 0, 0);
}

void complete_default_scene(t_scene *myscene)
{
	myscene->resolution.x = 500;
	myscene->resolution.y = 500;
}

void delete_cams(void *camera)
{
	free(((t_camera *)camera)->position);
}

void delete_objets(void *objs)
{
	free(((t_sphere *)objs)->position);
}

void delete_scene(t_scene *scene)
{
	ft_lstclear(&scene->cams, &delete_cams);
	ft_lstclear(&scene->objets, &delete_objets);
	free(scene);
}