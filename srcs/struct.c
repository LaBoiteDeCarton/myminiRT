#include "struct.h"

void	add_resolution(char **splited, t_scene *scene)
{
	if (*splited && ft_str_isalpha(*splited))
	{
		scene->resolution.x = ft_atoi(*splited);
		splited++;
	}
	if (*splited && ft_str_isalpha(*splited))
	{
		scene->resolution.y = ft_atoi(*splited);
		splited++;
	}	
}

void	add_to_scene(char *line, t_scene *scene)
{
	char **splited;

	splited = ft_split(line, ' ');
	if (!splited)
	{
		if (!ft_strncmp(*splited, "R", 2))
			add_resolution(splited + 1, scene);
	}
}