#include "fractol.h"

int	mandelbrot(t_complex c)
{
	int	i;
	t_complex z;

	i = 0;
	z = c;
	while (in_circle(z) && i < MAX_ITER)
	{
		z = add_comp(pow_two(z), c);
		i++;
	}
	return (get_color(i));
}

int	mandelbar(t_complex c)
{
	int	i;
	t_complex z;

	i = 0;
	z = c;
	while (in_circle(z) && i < MAX_ITER)
	{
		z = add_comp(pow_two(complex(z.re, -z.im)), c);
		i++;
	}
	return (get_color(i));
}

int	burning_ship(t_complex c)
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
		z = add_comp(complex(pow(re_abs, 2.0) - pow(im_abs, 2.0), -2.0 * re_abs * im_abs), c);
		i++;
	}
	return (get_color(i));
}

int	mandeldrop(t_complex c)
{
	int	i;
	t_complex 	z;

	i = 0;
	z =  complex(c.im, c.re);
	while(in_circle(z) && i < MAX_ITER)
	{
		z = sub_comp(pow_two(z), complex(c.im, c.re));
		i++;
	}
	return (get_color(i));
}

int	multi_mandel(t_complex c, int power)
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
		z = add_comp(z_pow, c);
		i++;
	}

	return (get_color(i));
}

int	buffalo(t_complex c) //buffalo
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
		z = add_comp(sub_comp(pow_two(complex(re_abs, im_abs)), complex(re_abs, im_abs)), complex(c.re, -c.im));
		i++;
	}
	return (get_color(i));
}

int	spider(t_complex c)
{
	int	i;
	t_complex 	z;

	i = 0;
	z = c;
	while (in_circle(z) && i < MAX_ITER)
	{
		z = add_comp(pow_two(z), c);
		c = add_comp(complex(c.re / 2.0, c.im / 2.0), z);
		i++;
	}
	return (get_color(i));
}
