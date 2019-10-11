#include "fractol.h"

void	set_pixel(t_fract *fract, int x, int y, int color)
{
	if ((x < 0 || x >= WIN_W) || (y < 0 || y >= WIN_H))
		return ;
	*(int *)(fract->data + (INDEX(x, y, WIN_W) * fract->bpp)) = color;
}

void	clear_image(t_fract *fract)
{
	ft_bzero(fract->data, WIN_W * WIN_H * fract->bpp);
}

void	put_image(t_fract *fract)
{
	mlx_put_image_to_window(fract->mlx, fract->win, fract->img, 0, 0);
}
