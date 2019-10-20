#include "fractol.h"

t_fract			*fract_init(char *name, t_type type)
{
	t_fract		*fract;
	char		*title;

	if (!(title = ft_strjoin("Fractol - ", name)))
		return (NULL);
	if (!(fract = (t_fract*)ft_memalloc(sizeof(t_fract))))
		return (NULL);
	if ((fract->mlx = mlx_init()) == NULL)
		fract_clear(&fract, MLX_INIT_ERR);
	if ((fract->win = mlx_new_window(fract->mlx, WIN_W, WIN_H, title)) == NULL)
		fract_clear(&fract, WINDOW_INIT_ERR);
	if ((fract->img = mlx_new_image(fract->mlx, WIN_W, WIN_H)) == NULL)
		fract_clear(&fract, IMAGE_INIT_ERR);
	if ((fract->data = mlx_get_data_addr(fract->img, &fract->bpp, \
	&fract->line_size, &fract->endian)) == NULL)
		fract_clear(&fract, DATA_ADDR_ERR);
	fract->bpp >>= 3;
	fract->type = type;
	fract->color_mode = 1;
	fract->inside_mode = 0;
	fract_init_helper(fract);
	hook_commands(fract);
	clear_image(fract);
	ft_strdel(&title);
	return (fract);
}

t_complex		complex(double re, double im)
{
	t_complex complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}

t_color		(*choose_func(t_type type))(t_complex, t_fract *)
{
	if (type == MANDELBROT)
		return (&mandelbrot);
	else if (type == MANDELBAR)
		return (&mandelbar);
	else if (type == MANDELDROP)
		return (&mandeldrop);
	else if (type == BURN_SHIP)
		return (&burning_ship);
	else if (type == BUFFALO)
		return (&buffalo);
	else if (type == CELTIC)
		return (&celtic);
	else if (type == SPIDER)
		return (&spider);
	else if (type == JULIA)
		return (&julia);
	return (NULL);
}

t_color		(*choose_func_2(t_type type))(t_complex, t_fract *)
{
	if (type == PHOENIX)
		return (&phoenix);
	else if (type == MANOWAR)
		return (&manowar);
	else if (type == NEWTON)
		return (&newton);
	else if (type == NOVA)
		return (&nova);
	else if (type == MULTIBROT)
		return (&multi_mandel);
	else if (type == MULTIJULIA)
		return (&multi_julia);
	return (NULL);
}

void	fract_init_helper(t_fract *fract)
{
	fract->re_range = range(-2.0, 2.0);
	fract->im_range = range(-2.0, 2.0);
	fract->scale.im = (fract->im_range.max - fract->im_range.min) / (WIN_H - 1);
	fract->scale.re = (fract->re_range.max - fract->re_range.min) / (WIN_W - 1);
	fract->julia_seed = complex(-0.4, 0.6);
	fract->max_iter = 50;
	ft_printf("type %d\n", fract->type);
	fract->multi_pow = 3;
	fract->static_mouse = 0;
	fract->func = (fract->type < 8) ? choose_func(fract->type) \
	: choose_func_2(fract->type);
}
