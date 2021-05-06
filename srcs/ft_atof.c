#include "utils.h"

#include <stdio.h>

double ft_atof(char *str)
{
	double	res;
	int		neg;
	int		d_rng;

	res = 0;
	neg = 0;
	res += ft_atoi(str);
	str = ft_strchr(str, '.');
	if (str)
	{
		str++;
		printf("le if ok\n");
		d_rng = 1;
		while (ft_isdigit(*str))
		{
			res = res + ((*str - '0') * pow(0.1, d_rng));
			str++;
			d_rng++;
		}
	}
	if (neg)
		res = -res;
	return (res);
}