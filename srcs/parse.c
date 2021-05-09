#include "parse.h"

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

static int a_to_int(char *str, t_rt *rt)
{
	if (!ft_strisdigit(str))
		handle_error("not a valid number", rt);
	return (ft_atoi(str));
}

static double a_to_float(char *str, t_rt *rt)
{
	if (!ft_strisfloat(str))
		handle_error("not a valid float", rt);
	return (ft_atof(str));
}

static void a_to_color(t_color *color, char *str, t_rt *rt)
{
	rt->parse.cmsplit = ft_split(str, ',');
	if (!rt->parse.cmsplit)
		handle_error(ERR_MALLOC, rt);
	color->r = a_to_int(rt->parse.cmsplit[0], rt);
	if (color->r > 255 || color < 0)
		handle_error("invalid color range", rt);
	color->g = a_to_int(rt->parse.cmsplit[1], rt);
	if (color->g > 255 || color < 0)
		handle_error("invalid color range", rt);
	color->b = a_to_int(rt->parse.cmsplit[2], rt);
	if (color->b > 255 || color < 0)
		handle_error("invalid color range", rt);
}

static void a_to_coord(t_coord *coord, char *str, t_rt *rt)
{
	rt->parse.cmsplit = ft_split(str, ',');
	if (!rt->parse.cmsplit)
		handle_error(ERR_MALLOC, rt);
	coord->x = a_to_float(rt->parse.cmsplit[0], rt);
	coord->y = a_to_float(rt->parse.cmsplit[1], rt);
	coord->z = a_to_float(rt->parse.cmsplit[2], rt);
}

static void a_to_nvect(t_vect *vect, char *str, t_rt *rt)
{
	rt->parse.cmsplit = ft_split(str, ',');
	if (!rt->parse.cmsplit)
		handle_error(ERR_MALLOC, rt);
	vect->x = a_to_float(rt->parse.cmsplit[0], rt);
	if (vect->x < -1 || vect->x > 1)
		handle_error(ERR_INVLINE, rt);
	vect->y = a_to_float(rt->parse.cmsplit[1], rt);
	if (vect->y < -1 || vect->y > 1)
		handle_error(ERR_INVLINE, rt);
	vect->z = a_to_float(rt->parse.cmsplit[2], rt);
	if (vect->z < -1 || vect->z > 1)
		handle_error(ERR_INVLINE, rt);
}

// static t_coord *parse_coord(char *str)
// {
// 	t_coord *coord;

// 	coord = malloc(sizeof(t_coord));
// 	if (!coord)
// 		return (NULL);
// 	coord->x = ft_atof(str);
// 	str = ft_strchr(str, ',');
// 	coord->y = ft_atof(str + 1);
// 	str = ft_strchr(str + 1, ',');
// 	coord->z = ft_atof(str + 1);
// 	return (coord);
// }

static void parse_resolution(t_rt *rt)
{
	if (rt->resolution.x >= 0 || rt->resolution.y >= 0)
		handle_error(ERR_RTWICE, rt);
	if (tabchar_len(rt->parse.spsplit) != 3)
		handle_error(ERR_RINVARGS, rt);
	rt->resolution.x = a_to_int(rt->parse.spsplit[1], rt);
	rt->resolution.y = a_to_int(rt->parse.spsplit[2], rt);
	if (rt->resolution.x <= 0 || rt->resolution.y <= 0)
		handle_error(ERR_RINVARGS, rt);
}

static void parse_ambientlight(t_rt *rt)
{
	if (rt->ambience.ratio >= 0)
		handle_error(ERR_ATWICE, rt);
	if (tabchar_len(rt->parse.spsplit) != 3)
		handle_error(ERR_AINVARGS, rt);
	rt->ambience.ratio = a_to_float(rt->parse.spsplit[1], rt);
	a_to_color(&rt->ambience.color, rt->parse.spsplit[2], rt);
	if (rt->ambience.ratio < 0 || rt->ambience.ratio > 1)
		handle_error(ERR_AINVARGS, rt);
}

static void parse_camera(t_rt *rt)
{
	t_camera *cam;
	t_list *lst_cam;

	if (tabchar_len(rt->parse.spsplit) != 4)
		handle_error(ERR_CINVARGS, rt);
	cam = malloc(sizeof(t_camera));
	if (!cam)
		handle_error(ERR_MALLOC, rt);
	lst_cam = ft_lstnew(cam);
	if (!lst_cam)
		handle_error(ERR_MALLOC, rt);
	ft_lstadd_back(&rt->cams, lst_cam);
	a_to_coord(&((t_camera *)lst_cam->content)->coord, rt->parse.spsplit[1],rt);
	a_to_nvect(&((t_camera *)lst_cam->content)->orient, rt->parse.spsplit[2],rt);
	((t_camera *)lst_cam->content)->fov = a_to_int(rt->parse.spsplit[3], rt);
	if (((t_camera *)lst_cam->content)->fov < 0
			|| ((t_camera *)lst_cam->content)->fov > 180)
		handle_error(ERR_INVLINE, rt);
}

static void parse_line(t_rt *rt)
{
	if (*(rt->parse.line) ) //si la ligne n'est pas vide
	{
		if (*(rt->parse.line) == ' ')
			handle_error(ERR_INVLINE, rt);
		rt->parse.spsplit = ft_split(rt->parse.line, ' ');
		if (!rt->parse.spsplit)
			handle_error(ERR_MALLOC, rt);
		if (!tabchar_len(rt->parse.spsplit))
			handle_error(ERR_INVLINE, rt);
		if (!ft_strncmp("R ", rt->parse.line, 2))
			parse_resolution(rt);
		else if (!ft_strncmp("A ", rt->parse.line, 2))
			parse_ambientlight(rt);
		else if (!ft_strncmp("c ", rt->parse.line, 2))
			parse_camera(rt);
		else
			handle_error(ERR_INVID, rt);
	}
}

void parse_file(char *file_name, t_rt *rt)
{
	int fd;
	int read;

	check_valid_filename(file_name, rt);
	open_file(&fd, file_name, rt);
	read = 1;
	while (read > 0)
	{
		read = get_next_line(fd, &(rt->parse.line));
		if (read < 0)
			handle_error(ERR_READINGFILEERROR, rt);
		if (!rt->parse.line)
			handle_error(ERR_MALLOC, rt);
		rt->parse.f_line++;
		parse_line(rt);
		free_parse(rt);
	}
	rt->parse.f_line = 0;
}