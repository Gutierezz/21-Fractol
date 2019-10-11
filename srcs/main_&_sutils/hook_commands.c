#include "fractol.h"

int		close_window(void *param)
{
	(void)param;
	exit(0);
}

// int		mouse_event(int key, int x, int y, void *param)
// {
// 	//t_fract *fract;
// 	(void)param;
// 	(void)key;
// 	(void)x;
// 	(void)y;
// 	// ft_printf("MOUSE AT : X: %d Y: %d\n", x, y);
// 	// ft_printf("mouse key code : %d\n", key);
// 	return (0);
// }

int	set_julia_seed(int x, int y, t_fract *fract)
{
	if (fract->type == JULIA || fract->type == MANOWAR || fract->type == TEST)
		fract->julia_seed = complex((4 * (double)x / WIN_W - 0.5), 4 *((double)(WIN_H - y) / WIN_H - 0.5));
	fill_image(fract);
	return(0);
}

int key_press(int key, t_fract *fract)
{
	if (key == VK_ESCAPE)
		exit (0);
	else if (key == VK_PLUS)
	{
		fract->scale.re += 0.005;
		fract->scale.im += 0.005;
	}
	else if (key == VK_MINUS)
	{
		fract->scale.re -= 0.005;
		fract->scale.im -= 0.005;
	}
	else if (key == VK_RIGHT && fract->multibrot_pow < 8)
	{
		fract->multibrot_pow++;
		ft_printf("power add %d\n", fract->multibrot_pow);
	}
	else if (key == VK_LEFT && fract->multibrot_pow > -8)
	{
		fract->multibrot_pow--;
		ft_printf("power minus %d\n", fract->multibrot_pow);
	}
	ft_printf("KEYBOARD code : %d\n", key);
	fill_image(fract);
	return (0);
}

void	hook_commands(t_fract *fract)
{
	if (fract->type == JULIA)
		mlx_hook(fract->win, 6, 1L<<6, set_julia_seed, fract);
	//mlx_mouse_hook(fract->win, mouse_event, fract);
	mlx_key_hook(fract->win, key_press, fract);
	mlx_hook(fract->win, 17, 1L<<17, close_window, fract);
}
