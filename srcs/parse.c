#include "parse.h"

static void free_tabchar(char **tabchar)
{
	//if (tabchar) //voir si tabchar est NULL...
	int i;

	i = 0;
	while (tabchar[i])
	{
		free(tabchar[i]);
		i++;
	}
	free(tabchar);
}

static int tabchar_len(char **tabchar)
{
	int size;

	size = 0;
	while (*tabchar)
	{
		size++;
		tabchar++;
	}
	return (size);
}

static void check_valid_filename(char *file_name, t_rt *rt)
{
	char *dot;

	dot = ft_strchr(file_name, '.');
	if (!dot)
		handle_error(ERR_BADEXTENTIONFILE, rt);
	if (ft_strncmp(".rt", dot, 4))  
	//WARNING "file.rt.rt" && "file.something.rt" unvalid, check if should be valid
	//if yes a simple while with dot = ft_strchr each time until dot == NULL would be great
		handle_error(ERR_BADEXTENTIONFILE, rt);
}

static void open_file(int *fd, char *file_name, t_rt *rt)
{
	*fd = open(file_name, O_RDONLY);
	if (*fd < 0)
		handle_error(ERR_UNABLETOOPENFILE, rt);
}

static void parse_color(char *line, char **splitted, char *str, t_rt *rt)
{
	t_color *color;

	color = malloc(sizeof(t_color));
	if (!color)
	{
		free(line);
		free_tabchar(splitted);
		handle_error(ERR_MALLOC, rt);
	}
	color->r = ft_atoi(str);
	str = ft_strchr(str, ',');
	str++;
	color->g = ft_atoi(str);
	str = ft_strchr(str, ',');
	str++;
	color->b = ft_atoi(str);
	rt->ambience.color = color;
}

static void parse_resolution(char *line, t_rt *rt)
{
	char **splitted;

	if (rt->resolution.x >= 0 || rt->resolution.y >= 0)
		handle_error(ERR_RTWICE, rt);
	splitted = ft_split(line, ' ');
	if (!splitted)
	{
		free(line);
		handle_error(ERR_MALLOC, rt);
	}
	if (tabchar_len(splitted) != 3 || !ft_strisdigit(splitted[1]) || !ft_strisdigit(splitted[2]))
	{
		free_tabchar(splitted);
		free(line);
		handle_error(ERR_RINVARGS, rt);
	}
	rt->resolution.x = ft_atoi(splitted[1]);
	rt->resolution.y = ft_atoi(splitted[2]);
	free_tabchar(splitted);
	free(line);
	if (rt->resolution.x <= 0 || rt->resolution.y <= 0)
		handle_error(ERR_RINVARGS, rt);
}

static void parse_ambientlight(char *line, t_rt *rt)
{
	char **splitted;

	if (rt->ambience.ratio >= 0 || rt->ambience.color)
		handle_error(ERR_ATWICE, rt);
	splitted = ft_split(line, ' ');
	if (!splitted)
	{
		free(line);
		handle_error(ERR_MALLOC, rt);
	}
	if (tabchar_len(splitted) != 3 || !ft_strisfloat(splitted[1]) || !ft_striscolor(splitted[2]))
	{
		free_tabchar(splitted);
		free(line);
		handle_error(ERR_AINVARGS, rt);
	}
	rt->ambience.ratio = ft_atof(splitted[1]);
	parse_color(line, splitted, splitted[2], rt);
	free_tabchar(splitted);
	free(line);
	if (rt->ambience.ratio < 0 || rt->ambience.ratio > 1)
		handle_error(ERR_AINVARGS, rt);
}

static void parse_camera(char *line, t_rt *rt)
{
	char **splitted;

	splitted = ft_split(line, ' ');
	if (!splitted)
	{
		free(line);
		handle_error(ERR_MALLOC, rt);
	}
	if (tabchar_len(splitted) != 4 || !ft_striscoord(splitted[1])
			|| !ft_striscolor(splitted[2]) || !ft_strisint(splitted[3]))
	{
		free_tabchar(splitted);
		free(line);
		handle_error(ERR_CINVARGS, rt);
	}
}

static void parse_line(char *line, t_rt *rt)
{
	if (*line) //si la ligne n'est pas vide
	{
		if (!ft_strncmp("R ", line, 2))
			parse_resolution(line, rt);
		if (!ft_strncmp("A ", line, 2))
			parse_ambientlight(line, rt);
		if (!ft_strncmp("c ", line, 2))
			parse_camera(line, rt);
	}
}

void parse_file(char *file_name, t_rt *rt)
{
	int fd;
	char *line;
	int read;

	check_valid_filename(file_name, rt);
	open_file(&fd, file_name, rt);
	line = NULL;
	read = 1;
	while (read > 0)
	{
		read = get_next_line(fd, &line);
		if (read < 0 && line)
			free(line);
		if (read < 0)
			handle_error(ERR_READINGFILEERROR, rt);
		if (!line)
			handle_error(ERR_MALLOC, rt);
		parse_line(line, rt);
		line = NULL;
	}
}