#include "fractol.h"

void		change_color_mode(int key, t_fract *fract)
{
	if (key == VK_1)
		fract->color_mode = 1;
	if (key == VK_2)
		fract->color_mode = 2;
	if (key == VK_3)
		fract->color_mode = 3;
	if (key == VK_4)
		fract->color_mode = 4;
	if (key == VK_5)
		fract->color_mode = 5;
}

void		move_image(int key, t_fract *fract)
{
	double 	step;

	if (key == VK_LEFT || key == VK_RIGHT)
	{
		step = (fract->re_range.max - fract->re_range.min) * MOVE_STEP;
		fract->re_range.min += (key == VK_RIGHT) ? step : -step;
		fract->re_range.max += (key == VK_RIGHT) ? step : -step;
	}
	if (key == VK_UP || key == VK_DOWN)
	{
		step = (fract->im_range.max - fract->im_range.min) * MOVE_STEP;
		fract->im_range.min += (key == VK_UP) ? step : -step;
		fract->im_range.max += (key == VK_UP) ? step : -step;
	}
}

void		maxiter_change(int key, t_fract *fract)
{
	int 	step;

	step = (int)(fract->max_iter * 0.05);
	if (key == VK_PLUS && fract->max_iter < 100000)
		fract->max_iter += (fract->max_iter < 50) ? 1 : step;
	if (key == VK_MINUS && fract->max_iter > 10)
		fract->max_iter += (fract->max_iter > 50) ? -step : -1;
}

void		shift_colors(t_fract *fract)
{
	fract->c1 = (fract->c1 + 1) % 3;
	fract->c2 = (fract->c2 + 1) % 3;
	fract->c3 = (fract->c3 + 1) % 3;
}

void		reset_fractal(t_fract *fract)
{
	fract->max_iter = 50;
	fract->re_range = range(-2.0, 2.0);
	fract->im_range = range(-2.0, 2.0);
	fract->scale.im = (fract->im_range.max - fract->im_range.min) / (WIN_H - 1);
	fract->scale.re = (fract->re_range.max - fract->re_range.min) / (WIN_W - 1);
}
