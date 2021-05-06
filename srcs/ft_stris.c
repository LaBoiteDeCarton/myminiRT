#include "utils.h"

int	ft_strisdigit(char *str)
{
	if (!str)
		return (0); //juste pour proteger au cas ou
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int ft_strisfloat(char *str)
{
	int dot;

	if (!str)
		return (0);
	if (!ft_isdigit(*str))
		return (0);
	str++;
	dot = 0;
	while (*str)
	{
		if (*str == '.' && !dot)
			dot = 1;
		else if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int ft_striscolor(char *str)
{
	(void)str;
	
	return (1);
}

int ft_striscoord(char *str)
{
	(void)str;
	return (1);
}

int ft_strisint(char *str)
{
	(void)str;
	return (1);
}