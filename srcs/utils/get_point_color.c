#include "fractol.h"
/*
static int	color_palette(double t)
{
	int black = 0x0;
	int red = 0xea0303;
	int orange = 0xf66300;
	int white = 0xffffff;
	int lblue = 0x68e3d4;
	int turquose = 0x00f6fd;

	int start;
	int end;
	if (t < 0.2)
	{
		start = turquose;
		end = lblue;
	}
	if (t < 0.4)
	{
		start = lblue;
		end = white;
	}
	if (t < 0.6)
	{
		start = white;
		end = orange;
	}
	if (t < 0.8)
	{
		start = orange;
		end = red;
	}
	if (t >= 0.8)
	{
		start = red;
		end = black;
	}
	int color = (int)(start + t * (end - start));  // интерполяция цвета
	return (color);
}
*/

t_color		color_init(double iter, t_complex last_z, double smooth)
{
	t_color color;

	color.iter = iter;
	color.z = last_z;
	color.smooth = smooth;
	return (color);
}

static int color_func(double i,double f, double p)
{
    return ((int)pow(255*(cos(sqrt(i) * f + p)), 2.0));
}


int		get_color(t_color col_p, t_fract *fract)
{
	double	perc;
	int 	color;

	perc = 0.0;
	color = 0;
	if ((int)col_p.iter >= fract->max_iter)
		return (color);
	if (fract->color_mode == 1)
	{
		perc = col_p.iter / (double)fract->max_iter;
		color |= (int)(9 * (1 - perc) * pow(perc, 3) * 255) << 16;
		color |= (int)(15 * pow((1 - perc),2) * pow(perc, 2) * 255) << 8;
		color |= (int)(8.5 * pow((1 - perc), 3)  * perc * 255);
	}
	else if (fract->color_mode == 2)
	{
		perc = col_p.smooth;
		color |= (int)(sin(perc) * 160 + 65) << 16;
		color |= (int)(sin(perc) * 20 + 35) << 8;
		color |= (int)(sin(perc) * 120 + 60);
	}
	else if (fract->color_mode == 3)
	{
		perc = col_p.iter;
		color |= color_func(perc, 1, 0) << 16;
		color |= color_func(perc, 1, 120) << 8;
		color |= color_func(perc, 1, 240);
	}
	return (color);
}

