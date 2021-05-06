#include <stdlib.h>
#include "mlx.h"
#include "handle_errors.h"
#include "parse.h"

int main(int ac, char **av)
{
	t_rt *rt;

	rt = rt_new();
	if (ac == 1)
		handle_error(ERR_ARGUMENTMISSING, rt);
	if (ac > 3)
		handle_error(ERR_TOOMUCHARGUMENT, rt);
	if (ac == 3)
		rt_addflag(av[2], rt);
	parse_file(av[1], rt);
	printf("Check for Resolution\n");
	printf("Resolution : (x,y) - (%d,%d)\n", rt->resolution.x, rt->resolution.y);
	printf("Check for Ambient Light\n");
	printf("Ambience light : (ratio) - (%f)\n", rt->ambience.ratio);
	printf("Ambient color : (r,g,b) - (%d,%d,%d)\n", rt->ambience.color->r, rt->ambience.color->g, rt->ambience.color->b);
	// rt_start(rt);
	// rt_delete(rt);
	return (1);
}