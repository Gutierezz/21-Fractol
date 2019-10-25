/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 12:54:45 by ttroll            #+#    #+#             */
/*   Updated: 2019/10/25 18:16:54 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color		default_color(t_colp colp, t_fract *fract)
{
	t_color	ucol;
	double	perc;

	ucol.color = 0;
	perc = colp.iter;
	ucol.ch[fract->c1] = (t_uchar)(255 - perc * 5.1);
	ucol.ch[fract->c2] = (t_uchar)(perc * 25) % 255;
	ucol.ch[fract->c3] = (t_uchar)(255 - perc * 3.5);
	return (ucol);
}

t_color		trippy_color(t_colp colp, t_fract *fract)
{
	t_color ucol;
	double	perc;

	ucol.color = 0;
	perc = (fract->coldiv_flag) ? colp.iter / fract->max_iter : colp.iter;
	ucol.ch[fract->c1] = (t_uchar)(pow(255 * (cos(sqrt(perc) + 0)), 2.0));
	ucol.ch[fract->c2] = (t_uchar)(pow(255 * (cos(sqrt(perc) + 120)), 2.0));
	ucol.ch[fract->c3] = (t_uchar)(pow(255 * (cos(sqrt(perc) + 240)), 2.0));
	return (ucol);
}

t_color		cookbook_color(t_colp colp, t_fract *fract)
{
	double	perc;
	t_color ucol;

	ucol.color = 0;
	perc = colp.iter / (double)fract->max_iter;
	ucol.ch[fract->c1] = (t_uchar)(9 * (1 - perc) * pow(perc, 3) * 255);
	ucol.ch[fract->c2] = (t_uchar)(15 * pow((1 - perc), 2) * pow(perc, 2) \
	* 255);
	ucol.ch[fract->c3] = (t_uchar)(8.5 * pow((1 - perc), 3) * perc * 255);
	return (ucol);
}

t_color		sin_color(t_colp colp, t_fract *fract)
{
	double	perc;
	t_color ucol;

	ucol.color = 0;
	perc = colp.iter + colp.z.re + colp.z.im;
	perc /= (fract->coldiv_flag) ? 1 : fract->max_iter;
	ucol.ch[fract->c3] = (t_uchar)(4.4 * pow(1.0 - perc, 2) * 255);
	ucol.ch[fract->c2] = (t_uchar)(2.7 * (1.0 - pow(perc, 1) * 255));
	ucol.ch[fract->c1] = (t_uchar)(3.3 * pow(perc, 3) * 255);
	return (ucol);
}
