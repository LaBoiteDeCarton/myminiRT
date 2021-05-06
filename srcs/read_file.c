#include "read_file.h"

#include <stdio.h>
#include <unistd.h>

void add_coord(t_coord *coord, char *str)
{
	char **split;

	split = ft_split(str, ',');
	printf("aftersplit\n");
	coord->x = ft_atof(split[0]);
	free(split[0]);
	coord->y = ft_atof(split[1]);
	free(split[1]);
	coord->z = ft_atof(split[2]);
	free(split[2]);
	printf("x = %f\n", coord->x);
	printf("y = %f\n", coord->y);
	printf("z = %f\n", coord->z);
	printf("endofaddcoord\n");
}

void add_object_sphere(char **splited, t_scene *scene)
{
	t_objet *sphere;
	char **split;

	sphere = malloc(sizeof(t_objet));
	sphere->objtype = sp;
	sphere->obj = malloc(sizeof(t_sphere));
	if (*splited)
	{
		((t_sphere *)sphere->obj)->position = malloc(sizeof(t_coord));
		add_coord(((t_sphere *)sphere->obj)->position, *splited);
		free(*splited);
		splited++;
	}
	if (*splited)
	{
		((t_sphere *)sphere->obj)->diam = ft_atof(*splited);
		splited++;
	}
	if (*splited)
	{
		split = ft_split(*splited, ',');
		sphere->color.r = ft_atoi(split[0]);
		sphere->color.g = ft_atoi(split[1]);
		sphere->color.b = ft_atoi(split[2]);
	}
	scene->objets = malloc(sizeof(t_objet *));
	ft_lstadd_front(&scene->objets, ft_lstnew(sphere));
}

void add_resolution(char **splited, t_scene *scene)
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

static void from_line_to_scene(char *line, t_scene *scene)
{
	char **splited;

	splited = ft_split(line, ' ');
	if (splited)
	{
		if (!ft_strncmp(*splited, "R", 2))
			add_resolution(splited + 1, scene);
		if (!ft_strncmp(*splited, "sp", 3))
			add_object_sphere(splited + 1, scene);
	}
}

int read_file(char *file_name, t_scene *scene)
{
	int fd;
	char *line;
	int reading;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		handle_error(ERR_UNABLETOOPENFILE, scene);
	printf("file %s opened sucessfully\n", file_name);
	reading = 1;
	line = NULL;
	while (reading > 0)
	{
		reading = get_next_line(fd, &line);
		from_line_to_scene(line, scene);
		free(line);
		line = NULL;
	}
	return (1);
}