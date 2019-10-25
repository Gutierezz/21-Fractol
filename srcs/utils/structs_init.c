/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 18:02:48 by ttroll            #+#    #+#             */
/*   Updated: 2019/10/25 18:27:33 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fract				*fract_init(char *name, t_type type, void *mlx, \
int *win_cnt)
{
	t_fract		*fract;
	char		*title;

	if (!(title = ft_strjoin("Fractol - ", name)))
		error_exit(MEM_ALLOC_ERR);
	if (!(fract = (t_fract*)ft_memalloc(sizeof(t_fract))))
		error_exit(MEM_ALLOC_ERR);
	fract->mlx = mlx;
	if ((fract->win = mlx_new_window(fract->mlx, WIN_W, WIN_H, title)) == NULL)
		fract_clear(&fract, WINDOW_INIT_ERR);
	if ((fract->img = mlx_new_image(fract->mlx, WIN_W, WIN_H)) == NULL)
		fract_clear(&fract, IMAGE_INIT_ERR);
	if ((fract->data = mlx_get_data_addr(fract->img, &fract->bpp, \
	&fract->line_size, &fract->endian)) == NULL)
		fract_clear(&fract, DATA_ADDR_ERR);
	fract->bpp >>= 3;
	fract->win_cnt = win_cnt;
	fract->type = type;
	fract->color_mode = 1;
	fract->inside_mode = 0;
	fract_init_helper(fract);
	hook_commands(fract);
	clear_image(fract);
	ft_strdel(&title);
	return (fract);
}

t_complex			complex(double re, double im)
{
	t_complex		complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}

static t_colp		(*choose_func(t_type type))(t_complex, t_fract *)
{
	static t_colp	(*funcs[])(t_complex, t_fract*) = \
	{&mandelbrot, \
	&burning_ship, \
	&celtic, \
	&spider, \
	&julia, \
	&phoenix, \
	&manowar, \
	&newton, \
	&nova, \
	&multi_mandel, \
	&multi_julia};

	return (funcs[type]);
}

void				fract_init_helper(t_fract *fract)
{
	fract->re_range = range(-2.0, 2.0);
	fract->im_range = range(-2.0, 2.0);
	fract->scale.im = (fract->im_range.max - fract->im_range.min) / (WIN_H - 1);
	fract->scale.re = (fract->re_range.max - fract->re_range.min) / (WIN_W - 1);
	if (fract->type == JULIA || fract->type == MULTIJULIA)
		fract->julia_seed = complex(-0.4, 0.6);
	if (fract->type == PHOENIX)
		fract->julia_seed = complex(0.5667, 0.0);
	if (fract->type == MANOWAR)
		fract->julia_seed = complex(-0.1, 0.0);
	fract->max_iter = 50;
	fract->multi_pow = 3;
	fract->static_mouse = 0;
	fract->func = choose_func(fract->type);
	fract->c1 = 2;
	fract->c2 = 1;
	fract->c3 = 0;
	fract->coldiv_flag = 0;
	fract->scale_num = 1.0;
}
