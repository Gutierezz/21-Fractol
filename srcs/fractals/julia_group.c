/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_group.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:04:00 by ttroll            #+#    #+#             */
/*   Updated: 2019/10/25 15:14:48 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_colp			manowar(t_complex c, t_fract *fract)
{
	int			i;
	t_complex	z;
	t_complex	z_prev;
	t_complex	tmp;

	i = 0;
	z_prev = complex(0.0, 0.0);
	z = c;
	while (in_circle(z) && i < fract->max_iter)
	{
		tmp = z;
		z = add_comp(add_comp(pow_two(z), z_prev), fract->julia_seed);
		z_prev = tmp;
		i++;
	}
	return (color_init((double)i, z));
}

t_colp			julia(t_complex c, t_fract *fract)
{
	int			i;
	t_complex	z;

	i = 0;
	z = c;
	while (in_circle(z) && i < fract->max_iter)
	{
		z = add_comp(comppow(z, 2), fract->julia_seed);
		i++;
	}
	return (color_init((double)i, z));
}

t_colp			multi_julia(t_complex c, t_fract *fract)
{
	int			i;
	t_complex	z;
	t_complex	z_pow;

	i = 0;
	z = c;
	while (in_circle(z) && i < fract->max_iter)
	{
		z_pow = comppow(z, fract->multi_pow);
		z = add_comp(z_pow, fract->julia_seed);
		i++;
	}
	return (color_init((double)i, z));
}

t_colp			phoenix(t_complex c, t_fract *fract)
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
		z = add_comp(add_comp(pow_two(z), fract->julia_seed), \
		complex(-0.5 * z_prev.re, -0.5 * z_prev.im));
		z_prev = tmp;
		i++;
	}
	return (color_init((double)i, z));
}
