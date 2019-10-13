#ifndef	FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <pthread.h>
# include "libft.h"
# include "ft_printf.h"
# include "mlx.h"
# include "my_keys.h"

# define WIN_W 800
# define WIN_H 800
# define THREADS_NUM 8

# define PI 3.14159265359

# define INDEX(x, y, size) (y * size + x)

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
	MANDELBAR,
	MANDELDROP,
	BURN_SHIP,
	BUFFALO,
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

typedef struct	s_range
{
	double		min;
	double		max;
}				t_range;

// typedef struct	s_mouse
// {
// 	int			x;
// 	int			y;
// }				t_mouse;

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
	int			multi_pow;
	int			(*func)(t_complex, struct s_fract *);
	int			max_iter;
	int			static_mouse;
	t_complex	scale;
	t_range		re_range;
	t_range		im_range;
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
int				(*choose_func(t_type type))(t_complex, t_fract *);
int				(*choose_func_2(t_type type))(t_complex, t_fract *);
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

int			get_color(int i, int max_iter);
int			other(t_complex c);

/*
** julia_group
*/

int			julia(t_complex c, t_fract *fract);
int			manowar(t_complex c, t_fract *fract);
int			phoenix(t_complex c, t_fract *fract);
int			multi_julia(t_complex c, t_fract *fract);

/*
**	newton_group
*/

int			newton(t_complex c, t_fract *fract);
int			nova(t_complex c, t_fract *fract);

/*
** mandel_group
*/

int			mandelbrot(t_complex c, t_fract *fract);
int			mandelbar(t_complex c, t_fract *fract);
int			burning_ship(t_complex c, t_fract *fract);
int			mandeldrop(t_complex c, t_fract *fract);
int			multi_mandel(t_complex c, t_fract *fract);
int			buffalo(t_complex c, t_fract *fract);
int			spider(t_complex c, t_fract *fract);
int			celtic(t_complex c, t_fract *fract);

#endif
