/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 13:11:50 by ttroll            #+#    #+#             */
/*   Updated: 2019/10/25 17:19:36 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int					set_julia_seed(int x, int y, t_fract *fract)
{
	if ((x > 0 && x < WIN_W) && (y > 0 && y < WIN_H))
	{
		if (fract->static_mouse == 0)
			fract->julia_seed = complex(((double)x * fract->scale.re - 2.0), \
					((double)(WIN_H - y) * fract->scale.im - 2.0));
		fill_image(fract);
	}
	return (0);
}

int					mouse_zoom(int key, int x, int y, t_fract *fract)
{
	t_complex		mouse_pos;
	double			zoom;

	if (key == WHEEL_UP || key == WHEEL_DOWN \
	|| key == MOUSE_LEFT || key == MOUSE_RIGHT)
	{
		mouse_pos.re = map(x, range(0, WIN_W), fract->re_range);
		mouse_pos.im = map(WIN_H - y, range(0, WIN_H), fract->im_range);
		zoom = (key == WHEEL_DOWN || key == MOUSE_RIGHT) ? 0.9 : 1.1;
		if (zoom > 1.0 && fract->scale_num > 3.5e13)
			return (0);
		fract->scale_num *= zoom;
		fract->re_range.min = lerp(1 / zoom, mouse_pos.re, fract->re_range.min);
		fract->re_range.max = lerp(1 / zoom, mouse_pos.re, fract->re_range.max);
		fract->im_range.min = lerp(1 / zoom, mouse_pos.im, fract->im_range.min);
		fract->im_range.max = lerp(1 / zoom, mouse_pos.im, fract->im_range.max);
		fill_image(fract);
	}
	return (0);
}

int					key_press(int key, t_fract *fract)
{
	if (key == VK_ESCAPE)
	{
		fract_clear(&fract, 0);
		exit(0);
	}
	else if (key == VK_R)
		reset_fractal(fract);
	else if (key == VK_SPACE)
		fract->static_mouse = (fract->static_mouse == 1) ? 0 : 1;
	else if (key == VK_PLUS || key == VK_MINUS)
		maxiter_change(key, fract);
	else if (key == VK_RIGHT || key == VK_LEFT || \
	key == VK_UP || key == VK_DOWN)
		move_image(key, fract);
	else if ((key >= VK_1 && key <= VK_4) || key == VK_T || key == VK_C \
	|| key == VK_LESS || key == VK_MORE || key == VK_NUM_0)
		key_press_helper(key, fract);
	fill_image(fract);
	return (0);
}

void				key_press_helper(int key, t_fract *fract)
{
	if (key >= VK_1 && key <= VK_4)
		change_color_mode(key, fract);
	else if (key == VK_NUM_0)
		fract->inside_mode = (fract->inside_mode) ? 0 : 1;
	else if (key == VK_T)
		fract->coldiv_flag = (fract->coldiv_flag) ? 0 : 1;
	else if (key == VK_C)
		shift_colors(fract);
	else if (key == VK_LESS || key == VK_MORE)
	{
		if (key == VK_LESS)
			fract->multi_pow -= (fract->multi_pow > 2) ? 1 : 0;
		if (key == VK_MORE)
			fract->multi_pow += (fract->multi_pow < 6) ? 1 : 0;
	}
}

void				hook_commands(t_fract *fract)
{
	if (fract->type == JULIA || fract->type == MULTIJULIA || \
	fract->type == PHOENIX || fract->type == MANOWAR)
		mlx_hook(fract->win, 6, 0, set_julia_seed, fract);
	mlx_hook(fract->win, 4, 0, mouse_zoom, fract);
	mlx_hook(fract->win, 2, 0, key_press, fract);
	mlx_hook(fract->win, 17, 0, close_window, fract);
}
