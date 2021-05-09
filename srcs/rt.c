#include "rt.h"
#include "handle_errors.h"
#include "utils.h"

t_rt *rt_new()
{
	t_rt *rt;

	rt = malloc(sizeof(t_rt));
	if (!rt)
		handle_error(ERR_MALLOC, rt);
	rt->flag = window;
	rt->objs = NULL;
	rt->cams = NULL;
	rt->parse.line = NULL;
	rt->parse.spsplit = NULL;
	rt->parse.cmsplit = NULL;
	rt->parse.f_line = 0;
	rt->resolution.x = -1;
	rt->resolution.y = -1;
	rt->ambience.ratio = -1;
	return(rt);
}

void free_parse(t_rt *rt)
{
	free(rt->parse.line);
	free_tabchar(rt->parse.spsplit);
	free_tabchar(rt->parse.cmsplit);
	rt->parse.line = NULL;
	rt->parse.spsplit = NULL;
	rt->parse.cmsplit = NULL;
}

void rt_start(t_rt *rt)
{
	//a voir
	(void)rt;
}

void rt_delete(t_rt *rt)
{
	free_parse(rt);
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

