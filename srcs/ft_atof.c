#include "utils.h"

#include <stdio.h>

double ft_atof(char *str)
{
	double	res;
	int		d_rng;

	res = ft_atoi(str);
	str = ft_strchr(str, '.');
	if (str)
	{
		str++;
		d_rng = 1;
		while (ft_isdigit(*str))
		{
			res = res + ((*str - '0') * pow(0.1, d_rng));
			str++;
			d_rng++;
		}
	}
	return (res);
}