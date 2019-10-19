#include "fractol.h"

void	change_color_mode(int key, t_fract *fract)
{
	if (key == VK_1)
		fract->color_mode = 1;
	if (key == VK_2)
		fract->color_mode = 2;
	if (key == VK_3)
		fract->color_mode = 3;
	if (key == VK_4)
		fract->color_mode = 4;
}

void	move_image(int key, t_fract *fract)
{
	(void)fract;
	(void)key;
	// double step;

	// if (key == VK_LEFT || key == VK_RIGHT)
	// {
	// 	step = (fract->re_range.max - fract->re_range.min) * 0.05;
	// 	fract->re_range.min += (key == VK_RIGHT) ? step : -step;
	// 	fract->re_range.max += (key == VK_RIGHT) ? step : -step;
	// }
	// if (key == VK_UP || key == VK_DOWN)
	// {
	// 	step = (fract->im_range.max - fract->im_range.min) * 0.05;
	// 	fract->im_range.min += (key == VK_UP) ? step : -step;
	// 	fract->im_range.max += (key == VK_UP) ? step : -step;
	// }
}

void	maxiter_change(int key, t_fract *fract)
{
	if (key == VK_PLUS && fract->max_iter < 10000000)
		fract->max_iter = (fract->max_iter < 50) ? fract->max_iter++ : (int)(fract->max_iter * 1.05);
	if (key == VK_MINUS && fract->max_iter > 10)
		fract->max_iter = (fract->max_iter > 50) ? (int)(fract->max_iter * 0.95) : fract->max_iter--;
}
