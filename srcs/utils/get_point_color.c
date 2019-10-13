#include "fractol.h"

// int	other(t_complex c)  										//  BULL_FACE
// {
// 	int	i;
// 	t_complex z;
// 	t_complex up;
// 	t_complex down;

// 	i = 0;
// 	z = c;
// 	while (in_circle(z) && i < MAX_ITER)
// 	{
// 		up = (sub_comp(comppow(z, 4), complex(1.0, 0.0)));
// 		down = (add_comp(comppow(z, 4), complex(1.0, 0.0)));
// 		z = add_comp(comp_div(up, down), complex(-c.im, c.re));
// 		i++;
// 	}
// 	return (get_color(i));
// }

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

int	get_color(int i, int max_iter)
{
	double	t;

	t = (double)i / (double)max_iter;
	//return (color_palette(t));
	// int red = (int)((1 - t) * t *255);
	// int green = (int)((1 - t) * t *255);
	// int blue = (int)((1 - t) * t *255);
	int red = (int)(9 * (1 - t) * pow(t, 3) * 255);
	int green = (int)(15 * pow((1 - t),2) * pow(t, 2) * 255);
	int blue = (int)(8.5 * pow((1 - t), 3)  * t * 255);
	int color = (red << 16) | (green << 8) | (blue);
	return (color);
}

// int		newton(t_complex c)   // NEWTON
// {
// 	int	i;
// 	t_complex z;
// 	t_complex top;
// 	t_complex bot;


// 	i = 0;
// 	z = c;
// 	while (i < 100)
// 	{
// 		top = add_comp(comppow(z, 4), complex(1.0, 0.0));
// 		if (comp_abs(top) < 1e-5)
// 			break ;
// 		bot = real_mult(comppow(z, 2), 3.0);
// 		z = sub_comp(z, comlexcomp_div(top, bot));
// 		i++;
// 	}
// 	return (get_color(i));
// }
