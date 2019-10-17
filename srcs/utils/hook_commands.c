#include "fractol.h"

int		close_window(t_fract *fract)
{
	fract_clear(&fract, 0);
	exit (0);
}


int	set_julia_seed(int x, int y, t_fract *fract)
{
	if (fract->static_mouse == 0)
		fract->julia_seed = complex(((double)x * fract->scale.re - 2.0), \
				((double)(WIN_H - y) * fract->scale.im - 2.0));
	fill_image(fract);
	return(0);
}

int	mouse_zoom(int key, int x, int y, t_fract *fract)
{
	t_complex	mouse_pos;
	double		zoom;

	if (key == WHEEL_UP || key == WHEEL_DOWN || key == MOUSE_LEFT || key == MOUSE_RIGHT)
	{
		mouse_pos.re = map(x, range(0, WIN_W), fract->re_range);
		mouse_pos.im = map(WIN_H - y, range(0, WIN_H), fract->im_range);
		zoom = (key == WHEEL_DOWN || key == MOUSE_RIGHT) ? 0.9 : 1.1;
		fract->re_range.min = lerp(1 / zoom, mouse_pos.re, fract->re_range.min);
		fract->re_range.max = lerp(1 / zoom, mouse_pos.re, fract->re_range.max);
		fract->im_range.min = lerp(1 / zoom, mouse_pos.im, fract->im_range.min);
		fract->im_range.max = lerp(1 / zoom, mouse_pos.im, fract->im_range.max);
		fill_image(fract);
	}
	return (0);
}


int		key_press(int key, t_fract *fract)
{
	if (key == VK_ESCAPE)
	{
		fract_clear(&fract, 0);
		exit(0);
	}
	else if (key == VK_R)
	{
		fract->re_range = range(-2.0, 2.0);
		fract->im_range = range(-2.0, 2.0);
	}
	else if (key == VK_SPACE)
		fract->static_mouse = (fract->static_mouse == 1) ? 0 : 1;
	else if (key == VK_PLUS && fract->max_iter < 150)
		fract->max_iter++;
	else if (key == VK_MINUS && fract->max_iter > 50)
		fract->max_iter--;
	else if (key == VK_RIGHT && fract->multi_pow < 8)
		fract->multi_pow++;
	else if (key == VK_LEFT && fract->multi_pow > -8)
		fract->multi_pow--;
	fill_image(fract);
	return (0);
}

void	hook_commands(t_fract *fract)
{
	if (fract->type == JULIA || fract->type == MULTIJULIA)
		mlx_hook(fract->win, 6, 1L<<6, set_julia_seed, fract);
	mlx_mouse_hook(fract->win, mouse_zoom, fract);
	mlx_key_hook(fract->win, key_press, fract);
	mlx_hook(fract->win, 17, 1L<<17, close_window, fract);
}
