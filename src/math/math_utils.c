
#include "../../include/cub3d.h"

double	degrees_to_radians(double degrees)
{
	double	result;

	result = ((degrees * M_PI) / 180.0);
	return (result);
}

double	radiants_to_degrees(double radians)
{
	double	result;

	result = ((radians * 180.0) / M_PI);
	return (result);
}

double abs_double(double number)
{
    if (number < 0)
        return (-number);
    else
    return (number);
}
