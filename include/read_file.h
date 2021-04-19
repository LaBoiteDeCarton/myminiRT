#ifndef READ_FILE_H
# define READ_FILE_H
# include "get_next_line.h"
# include "struct.h"
# include <fcntl.h>

int read_file(char *file_name, t_scene *scene);

#endif