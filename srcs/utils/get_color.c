/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 12:52:43 by ttroll            #+#    #+#             */
/*   Updated: 2019/10/25 17:26:10 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_colp		color_init(double iter, t_complex last_z)
{
	t_colp	colp;

	colp.iter = iter;
	colp.z = last_z;
	return (colp);
}

t_color		get_color(t_colp colp, t_fract *fract)
{
	if ((int)colp.iter >= fract->max_iter)
		return (inside_coloring(colp, fract));
	else if (fract->color_mode == 4)
		return (sin_color(colp, fract));
	else if (fract->color_mode == 2)
		return (cookbook_color(colp, fract));
	else if (fract->color_mode == 3)
		return (trippy_color(colp, fract));
	else
		return (default_color(colp, fract));
}

t_color		inside_coloring(t_colp colp, t_fract *fract)
{
	int		perc;
	t_color ucol;

	perc = colp.iter;
	ucol.color = 0;
	if (fract->inside_mode == 0)
		return (ucol);
	else if (fract->inside_mode == 1)
	{
		perc = colp.iter + colp.z.im / colp.z.re;
		ucol.ch[0] = (t_uchar)(perc * 3.9) % 255;
		ucol.ch[1] = (t_uchar)(255 - perc * 5.5);
		ucol.ch[2] = (t_uchar)(255 - perc * 8.5);
	}
	return (ucol);
}

int			close_window(t_fract *fract)
{
	int		last_window;

	last_window = (*(fract->win_cnt) == 1) ? 1 : 0;
	*(fract->win_cnt) -= 1;
	(void)fract->win_cnt;
	fract_clear(&fract, 0);
	if (last_window)
		exit(0);
	return (0);
}
