/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:42:48 by ttroll            #+#    #+#             */
/*   Updated: 2019/10/20 16:47:58 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <pthread.h>
# include "libft.h"
# include "ft_printf.h"
# include "mlx.h"
# include "my_keys.h"
//# include "keys.h"

# define WIN_W 800
# define WIN_H 800
# define THREADS_NUM 8

# define MOVE_STEP 0.1
# define PI 3.14159265359

# define INDEX(x, y, size) (y * size + x)

typedef unsigned char UCHAR;

typedef enum	s_err
{
	MLX_INIT_ERR = 1,
	WINDOW_INIT_ERR,
	IMAGE_INIT_ERR,
	DATA_ADDR_ERR,
	FDF_INIT_ERR,
	MEM_ALLOC_ERR,
	INVALID_NAME
}				t_err;

typedef enum	s_type
{
	MANDELBROT,
	BURN_SHIP,
	CELTIC,
	SPIDER,
	JULIA,
	PHOENIX,
	MANOWAR,
	NEWTON,
	NOVA,
	MULTIBROT,
	MULTIJULIA,
	INVALID
}				t_type;

typedef struct	s_complex
{
	double		re;
	double		im;
}				t_complex;

typedef	struct	s_colp
{
	double iter;
	t_complex z;
	double smooth;
}				t_colp;

typedef	union	u_color
{
	int			color;
	UCHAR		ch[4];
}				t_color;

typedef struct	s_range
{
	double		min;
	double		max;
}				t_range;

typedef struct	s_fract
{
	t_type		type;
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			bpp;
	int			line_size;
	int 		endian;
	int			thread_min_y;
	int			thread_max_y;
	int			color_mode;
	int			inside_mode;
	int			multi_pow;
	t_colp		(*func)(t_complex, struct s_fract *);
	int			max_iter;
	int			static_mouse;
	t_complex	scale;
	t_range		re_range;
	t_range		im_range;
	int 		c1;
	int 		c2;
	int			c3;
	t_complex	julia_seed;
}				t_fract;

/*
** hook_commands
*/

int		close_window(t_fract *fract);
int		mouse_zoom(int key, int x, int y, t_fract *fract);
int		set_julia_seed(int x, int y, t_fract *fract);
int		key_press(int key, t_fract *fract);
void	hook_commands(t_fract *fract);

/*
** key_press_utils
*/

void	move_image(int key, t_fract *fract);
void	change_color_mode(int key, t_fract *fract);
void	maxiter_change(int key, t_fract *fract);
void	shift_colors(t_fract *fract);

/*
** fill_image
*/

double			lerp(double norm, double min, double max);
double			norm(double value, double min, double max);
double			map(double value, t_range pixel, t_range comp);
void			*fill_area(t_fract *fract);
void			fill_image(t_fract *fract);

/*
** structs_init
*/

t_fract			*fract_init(char *name, t_type type);
t_complex		complex(double re, double im);
t_colp			(*choose_func(t_type type))(t_complex, t_fract *);
t_colp				(*choose_func_2(t_type type))(t_complex, t_fract *);
void			fract_init_helper(t_fract *fract);

/*
** structs_clear
*/

void			fract_clear(t_fract **fract, int err_msg);
void			error_exit(int err);

/*
** image_funcs
*/

void			set_pixel(t_fract *fract, int x, int y, int color);
void			clear_image(t_fract *fract);
void			put_image(t_fract *fract);
t_range			range(double min, double max);

/*
** complex_ops
*/

void			comp_print(t_complex c);
t_complex		pow_two(t_complex c);
t_complex		comppow(t_complex c, int power);
t_complex		real_mult(t_complex c, double num);
t_complex		reverse_comp(t_complex c);
double			comp_abs(t_complex c);
int				in_circle(t_complex c);

/*
** complex_arithmetics
*/

t_complex		comp_mult(t_complex c1, t_complex c2);
t_complex		comp_div(t_complex c1, t_complex c2);
t_complex		add_comp(t_complex c1, t_complex c2);
t_complex		sub_comp(t_complex c1, t_complex c2);

/*
** get_point_color
*/

t_colp			color_init(double iter, t_complex last_z, double smooth);
t_color			inside_coloring(t_colp colp, t_fract *fract);
t_color			get_color(t_colp color, t_fract *fract);

/*
** julia_group
*/

t_colp			julia(t_complex c, t_fract *fract);
t_colp			manowar(t_complex c, t_fract *fract);
t_colp			phoenix(t_complex c, t_fract *fract);
t_colp			multi_julia(t_complex c, t_fract *fract);

/*
**	newton_group
*/

t_colp			newton(t_complex c, t_fract *fract);
t_colp			nova(t_complex c, t_fract *fract);

/*
** mandel_group
*/

t_colp				mandelbrot(t_complex c, t_fract *fract);
t_colp				burning_ship(t_complex c, t_fract *fract);
t_colp				multi_mandel(t_complex c, t_fract *fract);
t_colp				buffalo(t_complex c, t_fract *fract);
t_colp				spider(t_complex c, t_fract *fract);
t_colp				celtic(t_complex c, t_fract *fract);

#endif
