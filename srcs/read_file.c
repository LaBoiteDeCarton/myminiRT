#include "read_file.h"

#include <stdio.h>
#include <unistd.h>

int read_file(char *file_name, t_scene *scene)
{
	int fd;
	char *line;
	int reading;

	fd = open(file_name, O_RDONLY);
	reading = 1;
	line = NULL;
	while (reading > 0)
	{
		reading = get_next_line(fd, &line);
		printf("%s\n", line);
		add_to_scene(line, scene);
		free(line);
	}
	return (1);
}