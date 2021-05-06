#include "handle_errors.h"

void handle_error(char *err, t_rt *rt)
{
	(void)rt; //l'idée c'est de tout free

	printf("Error\n%s\n", err);
	if (rt) //handle le cas ou l'erreur previent du malloc de rt
		rt_delete(rt);
	exit(EXIT_FAILURE);
}
