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
	if ((fract->data = mlx_get_data_addr(fract->img, &fract->bpp, &fract->line_size, &fract->endian)) == NULL)
		fract_clear(&fract, DATA_ADDR_ERR);
	fract->bpp >>= 3;
	fract->type = type;
	hook_commands(fract);
	clear_image(fract);
	min_max_limits(fract);
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

void	min_max_limits(t_fract *fract)
{
		fract->min = complex(-2.0, -2.0);
		fract->max = complex(2.0, 2.0);//fract->min_lim.im + 4.0 * WIN_H / WIN_W);
		fract->scale.im = (fract->max.im - fract->min.im) / (WIN_H - 1);
		fract->scale.re = (fract->max.re - fract->min.re) / (WIN_W - 1);
		comp_print(fract->scale);
		comp_print(fract->max_lim);
		comp_print(fract->min_lim);
		fract->julia_seed = complex(-0.8, 0);
		fract->multi_pow = 2;
	// }
}
