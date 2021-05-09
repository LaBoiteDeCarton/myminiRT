#include "utils.h"

void free_tabchar(char **tabchar)
{
	int i;

	if (tabchar) //voir si tabchar est NULL...
	{
		i = 0;
		while (tabchar[i])
		{
			free(tabchar[i]);
			i++;
		}
		free(tabchar);
	}
}

int tabchar_len(char **tabchar)
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