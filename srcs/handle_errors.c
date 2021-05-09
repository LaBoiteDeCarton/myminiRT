#include "handle_errors.h"

void handle_error(char *err, t_rt *rt)
{
	(void)rt; //l'idée c'est de tout free

	printf("Error\n");
	if (rt->parse.f_line)
		printf("File, Line %d: ", rt->parse.f_line);
	printf("%s\n", err);
	if (rt) //handle le cas ou l'erreur previent du malloc de rt
		rt_delete(rt);
	exit(EXIT_FAILURE);
}
