#include "fractol.h"

int	manowar(t_complex c, t_fract *fract)  // MANOWAR
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
	return (i);
}

int	julia(t_complex c, t_fract *fract)
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
	return (i);
}

int	multi_julia(t_complex c, t_fract *fract)  // MULTIJULIA WORK_FINE
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
	return (i);
}

int	phoenix(t_complex c, t_fract *fract)  // phoenix
{
	int			i;
	t_complex	z;
	t_complex	z_prev;
	t_complex	tmp;
	t_complex	seed;

	i = 0;
	seed = complex(0.5667, 0.0);
	z_prev = complex(0.0, 0.0);
	z = complex(c.im, c.re);
	while(in_circle(z) && i < fract->max_iter)
	{
		tmp = z;
		z = add_comp(add_comp(pow_two(z), seed), complex(-0.5 * z_prev.re, -0.5 * z_prev.im));
		z_prev = tmp;
		i++;
	}
	return (i);
}
