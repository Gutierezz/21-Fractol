/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton_group.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:16:45 by ttroll            #+#    #+#             */
/*   Updated: 2019/10/25 15:16:46 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_colp			nova(t_complex c, t_fract *fract)
{
	int			i;
	t_complex	z;
	t_complex	top;
	t_complex	bot;
	t_complex	prev_z;

	i = 0;
	prev_z = complex(0.0, 0.0);
	z = complex(1.0, 0.0);
	while (i < fract->max_iter)
	{
		if (comp_abs(sub_comp(z, prev_z)) < 1e-5)
			break ;
		top = sub_comp(comppow(z, 3), complex(1.0, 0.0));
		bot = real_mult(comppow(z, 2), 3.0);
		prev_z = z;
		z = add_comp(sub_comp(z, comp_div(top, bot)), complex(-c.im, c.re));
		i++;
	}
	return (color_init((double)i, z));
}

t_colp			newton(t_complex c, t_fract *fract)
{
	int			i;
	t_complex	z;
	t_complex	top;
	t_complex	bot;

	i = 0;
	z = c;
	if (fract->multi_pow < 3)
		fract->multi_pow = 3;
	while (i < fract->max_iter)
	{
		top = sub_comp(comppow(z, fract->multi_pow), complex(1.0, 0.0));
		if (comp_abs(top) < 1e-5)
			break ;
		bot = real_mult(comppow(z, fract->multi_pow - 1), fract->multi_pow);
		z = sub_comp(z, comp_div(top, bot));
		i++;
	}
	return (color_init((double)i, z));
}
