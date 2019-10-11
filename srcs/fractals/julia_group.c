#include "fractol.h"

int	manowar(t_complex c)  // MANOWAR
{
	int	i;
	t_complex z;
	t_complex z_prev;
	t_complex tmp;

	i = 0;
	z_prev = complex(0.0, 0.0);
	z = c;
	while(in_circle(z) && i < MAX_ITER)
	{
		tmp = z;
		z = add_comp(add_comp(pow_two(z), z_prev), complex(-0.1, 0.0));
		z_prev = tmp;
		i++;
	}
	return (get_color(i));
}

int	julia(t_complex c, t_complex julia_seed)
{
	int	i;
	t_complex z;

	i = 0;
	z = c;
	while(in_circle(z) && i < MAX_ITER)
	{
		z = add_comp(pow_two(z), julia_seed);
		i++;
	}
	return (get_color(i));
}

int	multi_julia(t_complex c, int power, t_complex julia_seed)  // MULTIJULIA WORK_FINE
{
	int	i;
	t_complex 	z;
	t_complex	z_pow;

	i = 0;
	z = c;
	while (in_circle(z) && i < MAX_ITER)
	{
		if (power == 0)
			z_pow = complex(1.0, 0.0);
		else
			z_pow = (power > 0) ? comppow(z, power) : reverse_comp(comppow(z, -power));
		z = add_comp(z_pow, julia_seed);
		i++;
	}
	//z = log (Iabs (z) + p)
	return (get_color(i));
}

int	phoenix(t_complex c)  // phoenix
{
	int	i;
	t_complex z;
	t_complex z_prev;
	t_complex tmp;

	i = 0;
	z_prev = complex(0.0, 0.0);
	z = complex(c.im, c.re);
	while(in_circle(z) && i < MAX_ITER)
	{
		tmp = z;
		z = add_comp(add_comp(pow_two(z), complex(0.5667, 0.0)), complex(-0.5 * z_prev.re, -0.5 * z_prev.im));
		z_prev = tmp;
		i++;
	}
	return (get_color(i));
}

int	burning_ship_julia(t_complex c)
{
	int	i;
	t_complex z;
	double	re_abs;
	double	im_abs;

	i = 0;
	z = c;
	while (in_circle(z) && i < MAX_ITER)
	{
		re_abs = fabs(z.re);
		im_abs = fabs(z.im);
		z = add_comp(complex(pow(re_abs, 2.0) - pow(im_abs, 2.0), -2.0 * re_abs * im_abs), complex(-0.598, 0.9225));
		i++;
	}
	return (get_color(i));
}
