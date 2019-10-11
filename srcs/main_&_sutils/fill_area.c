#include "fractol.h"

void	*fill_area(t_fract *fract)
{
	int	y;
	int	x;
	int	color;
	t_complex	c;

	//ft_printf("fill_area!!!!!!!!!!!!! \n");
	y = fract->thread_min_y;
	while (y < fract->thread_max_y)
	{
		c.im = fract->max_lim.im - y * fract->scale.im;
		x = -1;
		while (++x < WIN_W)
		{
			c.re = fract->min_lim.re + x * fract->scale.re;
			color = choose_fractal_method(c, fract);
			set_pixel(fract, x, y, color);
		}
		y++;
	}
	pthread_exit(0);
}

void	fill_image(t_fract *fract)
{
	int			i;
	pthread_t	threads[THREADS_NUM];
	t_fract		fracts[THREADS_NUM];

	i = -1;
	while (++i < THREADS_NUM)
	{
		fracts[i] = *fract;
		fracts[i].thread_min_y = i * 100;
		fracts[i].thread_max_y = (((i + 1) * 100) < WIN_H) ? ((i + 1) * 100) : WIN_H;
		pthread_create(&(threads[i]), NULL, (void *(*)(void*))fill_area, (void*)&fracts[i]);
	}
	while (i--)
		pthread_join(threads[i], NULL);
	put_image(fract);
	ft_printf("drawn!\n");
}
