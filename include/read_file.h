#ifndef READ_FILE_H
# define READ_FILE_H
# include "get_next_line.h"
# include "scene.h"
# include <fcntl.h>
# include "handle_errors.h"
# include "ft_atof.h"
# include "libft.h"

int read_file(char *file_name, t_scene *scene);

#endif