#include "fractol.h"

t_colp		mandelbrot(t_complex c, t_fract *fract)
{
	int			i;
	t_complex	z;

	i = 0;
	z = c;
	while (in_circle(z) && i < fract->max_iter)
	{
		z = add_comp(pow_two(z), c);
		i++;
	}
	return (color_init((double)i, z));
}

t_colp		burning_ship(t_complex c, t_fract *fract)
{
	int			i;
	t_complex	z;

	i = 0;
	z = c;
	while (in_circle(z) && i < fract->max_iter)
	{
		z = pow_two(complex(fabs(z.re), fabs(z.im)));
		z = add_comp(complex(z.re, -z.im), c);
		i++;
	}
	return (color_init((double)i, z));
}

t_colp		multi_mandel(t_complex c, t_fract *fract)
{
	int			i;
	t_complex	z;
	t_complex	z_pow;

	i = 0;
	z = c;
	while (in_circle(z) && i < fract->max_iter)
	{
		if (fract->multi_pow == 0)
			z_pow = complex(1.0, 0.0);
		else
			z_pow = (fract->multi_pow > 0) ? comppow(z, fract->multi_pow) : \
			reverse_comp(comppow(z, -fract->multi_pow));
		z = add_comp(z_pow, c);
		i++;
	}
	return (color_init((double)i, z));
}

t_colp		spider(t_complex c, t_fract *fract)
{
	int			i;
	t_complex	z;

	i = 0;
	z = c;
	while (in_circle(z) && i < fract->max_iter)
	{
		z = add_comp(pow_two(z), c);
		c = add_comp(complex(c.re / 2.0, c.im / 2.0), z);
		i++;
	}
	return (color_init((double)i, z));
}

t_colp		celtic(t_complex c, t_fract *fract)
{
	int			i;
	t_complex	z;

	i = 0;
	z = c;
	while (in_circle(z) && i < fract->max_iter)
	{
		z = pow_two(z);
		z = complex(fabs(z.re), z.im);
		z = add_comp(z, c);
		i++;
	}
	return (color_init((double)i, z));
}
