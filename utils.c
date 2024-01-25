#include "minirt.h"

void	free_tabl(char **tabl)
{
	int	i;

	i = 0;
	while (tabl[i])
	{
		free(tabl[i]);
		i++;
	}
	free(tabl);
}

int	free_tabl_ret1(char **tabl)
{
	int	i;

	i = 0;
	while (tabl[i])
	{
		free(tabl[i]);
		i++;
	}
	free(tabl);
	return (1);
}

#include <stdio.h>

float ft_atof(char *str)
{
    float result = 0.0f;
    float sign = 1.0f;
    float factor = 1.0f;
    
    while (*str == ' ')
        str++;
    if (*str == '-')
	{
        sign = -1.0f;
        str++;
	}
    else if (*str == '+')
        str++;
    while (*str != '\0')
	{
        if (*str == '.')
		{
            factor = 0.1f;
            str++;
            continue;
        }
		else if (*str >= '0' && *str <= '9')
		{
            if (factor > 0.5f)
                result = (result * 10.0f) + (*str - '0');
            else
			{
                result += (*str - '0') * factor;
                factor *= 0.1f;
            }
        }
		else
            return (-42000);
        str++;
    }
    return (result * sign);
}