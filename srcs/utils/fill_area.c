/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_area.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 17:16:33 by ttroll            #+#    #+#             */
/*   Updated: 2019/10/25 18:17:04 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double			lerp(double norm, double min, double max)
{
	return ((max - min) * norm + min);
}

double			norm(double value, double min, double max)
{
	return ((value - min) / (max - min));
}

double			map(double value, t_range pixel, t_range comp)
{
	return (lerp(norm(value, pixel.min, pixel.max), comp.min, comp.max));
}

void			*fill_area(t_fract *fract)
{
	int			y;
	int			x;
	t_color		cun;
	t_complex	c;
	t_colp		colp;

	y = fract->thread_min_y;
	while (y < fract->thread_max_y)
	{
		c.im = map(WIN_H - y, range(0, WIN_H), fract->im_range);
		x = -1;
		while (++x < WIN_W)
		{
			c.re = map(x, range(0, WIN_W), fract->re_range);
			colp = (*(fract->func))(c, fract);
			cun = get_color(colp, fract);
			set_pixel(fract, x, y, cun.color);
		}
		y++;
	}
	pthread_exit(0);
}

void			fill_image(t_fract *fract)
{
	int			i;
	pthread_t	threads[THREADS_NUM];
	t_fract		fracts[THREADS_NUM];

	i = -1;
	clear_image(fract);
	while (++i < THREADS_NUM)
	{
		fracts[i] = *fract;
		fracts[i].thread_min_y = i * 100;
		fracts[i].thread_max_y = (((i + 1) * 100) < WIN_H) ? \
		((i + 1) * 100) : WIN_H;
		pthread_create(&(threads[i]), NULL, \
		(void *(*)(void*))fill_area, (void*)&fracts[i]);
	}
	while (i--)
		pthread_join(threads[i], NULL);
	put_image(fract);
}
