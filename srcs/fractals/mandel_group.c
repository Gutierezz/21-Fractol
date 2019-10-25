/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel_group.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:16:25 by ttroll            #+#    #+#             */
/*   Updated: 2019/10/25 15:16:33 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_colp			mandelbrot(t_complex c, t_fract *fract)
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

t_colp			burning_ship(t_complex c, t_fract *fract)
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

t_colp			multi_mandel(t_complex c, t_fract *fract)
{
	int			i;
	t_complex	z;
	t_complex	z_pow;

	i = 0;
	z = c;
	while (in_circle(z) && i < fract->max_iter)
	{
		z_pow = comppow(z, fract->multi_pow);
		z = add_comp(z_pow, c);
		i++;
	}
	return (color_init((double)i, z));
}

t_colp			spider(t_complex c, t_fract *fract)
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

t_colp			celtic(t_complex c, t_fract *fract)
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
