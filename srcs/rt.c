#include "rt.h"
#include "handle_errors.h"

t_rt *rt_new()
{
	t_rt *rt;

	rt = malloc(sizeof(t_rt));
	if (!rt)
		handle_error(ERR_MALLOC, rt);
	rt->flag = window;
	rt->objs = NULL;
	rt->cams = NULL;
	rt->resolution.x = -1;
	rt->resolution.y = -1;
	rt->ambience.ratio = -1;
	rt->ambience.color = NULL;
	return(rt);
}

void rt_start(t_rt *rt)
{
	//a voir
	(void)rt;
}

void rt_delete(t_rt *rt)
{
	free(rt); //ajouter lstdel
}

void rt_addflag(char *flag, t_rt *rt)
{
	if (ft_strncmp("--save", flag, 7) == 0)
		rt->flag = save;
	else if (ft_strncmp("--window", flag, 9) == 0)
		rt->flag = window;
	else
		handle_error(ERR_WRONGFLAGARG, rt);
}

