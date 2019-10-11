#include "fractol.h"

int	choose_fractal_method(t_complex c, t_fract *fract)
{
	if (fract->type == MANDELBROT)
		return (mandelbrot(c));
	else if (fract->type == JULIA)
		return (julia(c, fract->julia_seed));
	else if (fract->type == BURN_SHIP)
		return (burning_ship(c));
	else if (fract->type == MANDELBAR)
		return (mandelbar(c));
	else if (fract->type == MANOWAR)
		return (manowar(c));
	else if (fract->type == MANDELDROP)
		return (mandeldrop(reverse_comp(c)));
	else if (fract->type == PHOENIX)
		return (phoenix(c));
	else if (fract->type == TEST)
		return (other(c));
	return (0);
}


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

int	get_color(int i)
{
	double	t;

	t = (double)i / (double)MAX_ITER;
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

// int		other(t_complex c)
// {  														 // NOVA TRY
// 	int	i;
// 	t_complex z;
// 	t_complex top;
// 	t_complex bot;

// 	i = 0;
// 	z = complex(1.0, 0.0);
// 	while (i < 100)
// 	{
// 		top = sub_comp(comppow(z, 3), complex(1.0, 0.0));
// 		if (comp_abs(top) < 1e-6)
// 			break ;
// 		bot = real_mult(comppow(z, 2), 3);
// 		z = add_comp(sub_comp(z, comp_div(top, bot)), c);
// 		i++;
// 	}
// 	return (get_color(i));
// }


// int		other(t_complex c)
// {  														 // NOVA TRY
// 	int	i;
// 	t_complex z;

// 	i = 0;
// 	z = c;
// 	while (in_circle(z) && i < MAX_ITER)
// 	{
// 		z =
// 		i++;
// 	}
// 	return (get_color(i));
// }
