#ifndef PARSE_H
# define PARSE_H
# include <fcntl.h>
# include "rt.h"
# include "libft.h"
# include "get_next_line.h"
# include "handle_errors.h"
# include "utils.h"

void parse_file(char *file_name, t_rt *rt);

#endif