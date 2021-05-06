#include "ft_str_utils.h"

int		ft_str_isalpha(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}