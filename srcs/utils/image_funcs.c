/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 18:17:28 by ttroll            #+#    #+#             */
/*   Updated: 2019/10/25 18:17:29 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		set_pixel(t_fract *fract, int x, int y, int color)
{
	if ((x < 0 || x >= WIN_W) || (y < 0 || y >= WIN_H))
		return ;
	*(int *)(fract->data + (INDEX(x, y, WIN_W) * fract->bpp)) = color;
}

void		clear_image(t_fract *fract)
{
	ft_bzero(fract->data, WIN_W * WIN_H * fract->bpp);
}

void		put_image(t_fract *fract)
{
	mlx_put_image_to_window(fract->mlx, fract->win, fract->img, 0, 0);
}

t_range		range(double min, double max)
{
	t_range	range;

	range.min = min;
	range.max = max;
	return (range);
}

int			in_circle(t_complex c)
{
	return (pow(c.re, 2.0) + pow(c.im, 2.0) <= 4.0);
}
