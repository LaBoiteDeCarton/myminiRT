#include "get_next_line.h"

#include <stdio.h>

static char	*ft_strjoin_and_free(char *s1, char *s2)
{
	char	*new_s;

	if (!s1)
		return(ft_strdup(s2));
	new_s = ft_strjoin(s1, s2);
	if (s1)
	{
		free(s1);
		s1 = NULL;
	}
	return (new_s);
}

int read_from_save(char **save, char **line)
{
	char *new_save;
	int reading;

	reading = 0;
	new_save = ft_strchr(*save, '\n');
	if (!new_save)
		reading = 1;
	else
		*new_save = 0;
	if (*save)
		*line = ft_strdup(*save);
	if (new_save)
		new_save = ft_strdup(new_save + 1);
	if (*save)
		free(*save);
	*save = new_save;
	return (reading);
}

int get_next_line(int fd, char **line)
{
	char buff[BUFFER_SIZE + 1];
	static char *save = NULL;
	int c_readed;
	int reading;

	reading = read_from_save(&save, line);
	while (reading)
	{
		reading = 0;
		c_readed = read(fd, buff, BUFFER_SIZE);
		if (c_readed == 0 && !*line)
			*line = ft_strdup("");
		if (c_readed <= 0)
			return (c_readed);
		buff[c_readed] = 0;
		save = ft_strchr(buff, '\n');
		if (!save)
			reading = 1;
		else
			*save = 0;
		*line = ft_strjoin_and_free(*line, buff);
		if (save)
			save = ft_strdup(save + 1);   
	}
	return (1);
}