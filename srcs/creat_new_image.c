#include "creat_new_image.h"

#include <stdio.h> // to remove

void *creat_new_image(void *mlx_ptr, t_scene *myscene)
{
	void *image;
	int pixel_bits;
	int line_bytes;
	int endian;
	char *buffer;
	// int color;
	// int i;
	// int pixel;
	(void)myscene;
	image = mlx_new_image(mlx_ptr, 100, 1);
	if (image == (void *)0)
		return ((void *)0);
	buffer = mlx_get_data_addr(image, &pixel_bits, &line_bytes, &endian);
	// color = 0x32323232;
	// i = 0;
	// while (i < 3200)
	// {
	// 	pixel = i * 4;
	// 	//printf("writing pixel : y = %d, x = %d\n", y, x);
	// 	if (endian == 1) // Most significant (Alpha) byte first
	// 	{
	// 		buffer[pixel + 0] = (color >> 24);
	// 		buffer[pixel + 1] = (color >> 16) & 0xFF;
	// 		buffer[pixel + 2] = (color >> 8) & 0xFF;
	// 		buffer[pixel + 3] = (color) & 0xFF;
	// 	}
	// 	else if (endian == 0) // Least significant (Blue) byte first
	// 	{
	// 		buffer[pixel + 0] = (color)&0xFF;
	// 		buffer[pixel + 1] = (color >> 8) & 0xFF;
	// 		buffer[pixel + 2] = (color >> 16) & 0xFF;
	// 		buffer[pixel + 3] = (color >> 24);
	// 	}
	// 	i++;
	// }
	return (image);
}
