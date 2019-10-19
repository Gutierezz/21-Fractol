#include "fractol.h"

t_color				manowar(t_complex c, t_fract *fract)
{
	int			i;
	t_complex	z;
	t_complex	z_prev;
	t_complex	tmp;

	i = 0;
	z_prev = complex(0.0, 0.0);
	z = c;
	while(in_circle(z) && i < fract->max_iter)
	{
		tmp = z;
		z = add_comp(add_comp(pow_two(z), z_prev), complex(-0.1, 0.0));
		z_prev = tmp;
		i++;
	}
	return (color_init((double)i, z, 0.0));
}

t_color		julia(t_complex c, t_fract *fract)
{
	int			i;
	t_complex	z;

	i = 0;
	z = c;
	while(in_circle(z) && i < fract->max_iter)
	{
		z = add_comp(comppow(z, 2), fract->julia_seed);
		i++;
	}
	return (color_init((double)i, z, 0.0));
}

t_color		multi_julia(t_complex c, t_fract *fract)
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
		z = add_comp(z_pow, fract->julia_seed);
		i++;
	}
	return (color_init((double)i, z, 0.0));
}

t_color		phoenix(t_complex c, t_fract *fract)
{
	int			i;
	t_complex	z;
	t_complex	z_prev;
	t_complex	tmp;

	i = 0;
	z_prev = complex(0.0, 0.0);
	z = complex(c.im, c.re);
	while (in_circle(z) && i < fract->max_iter)
	{
		tmp = z;
		z = add_comp(add_comp(pow_two(z), complex(0.5667, 0.0)), \
		complex(-0.5 * z_prev.re, -0.5 * z_prev.im));
		z_prev = tmp;
		i++;
	}
	return (color_init((double)i, z, 0.0));
}
