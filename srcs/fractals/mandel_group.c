#include "fractol.h"

int	mandelbrot(t_complex c, t_fract *fract)
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
	return (i);
}

int	mandelbar(t_complex c, t_fract *fract)
{
	int			i;
	t_complex	z;

	i = 0;
	z = c;
	while (in_circle(z) && i < fract->max_iter)
	{
		z = add_comp(pow_two(complex(z.re, -z.im)), c);
		i++;
	}
	return (i);
}

int	burning_ship(t_complex c, t_fract *fract)
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
	return (i);
}

int	mandeldrop(t_complex c, t_fract *fract)
{
	int			i;
	t_complex	z;

	i = 0;
	c = reverse_comp(c);
	z = c;
	while(in_circle(z) && i < fract->max_iter)
	{
		z = sub_comp(pow_two(z), c);
		i++;
	}
	return (i);
}

int	multi_mandel(t_complex c, t_fract *fract)
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

	return (i);
}

int	buffalo(t_complex c, t_fract *fract)
{
	int			i;
	t_complex	z;

	i = 0;
	c = complex(c.re, -c.im);
	z = c;
	while (in_circle(z) && i < fract->max_iter)
	{
		z = complex(fabs(z.re), fabs(z.im));
		z = add_comp(sub_comp(pow_two(z), z), c);
		i++;
	}
	return (i);
}


int	spider(t_complex c, t_fract *fract)
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
	return (i);
}

int	celtic(t_complex c, t_fract *fract)
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
	return (i);
}
