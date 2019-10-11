#include "fractol.h"

int		nova(t_complex c)   // NOVA
{
	int	i;
	t_complex z;
	t_complex top;
	t_complex bot;
	t_complex prev_z;

	i = 0;
	prev_z = complex(0.0, 0.0);
	z = complex(1.0, 0.0);
	while (i < MAX_ITER)
	{
		if (comp_abs(sub_comp(z, prev_z)) < 1e-8)
			break ;
		top = sub_comp(comppow(z, 3), complex(1.0, 0.0));
		bot = real_mult(comppow(z, 2), 3.0);
		prev_z = z;
		z = add_comp(sub_comp(z, comp_div(top, bot)), complex(-c.im, c.re));
		i++;
	}
	return (get_color(i));
}

int		newton(t_complex c)   // NEWTON
{
	int	i;
	t_complex z;
	t_complex top;
	t_complex bot;


	i = 0;
	z = c;
	while (i < MAX_ITER)
	{
		top = add_comp(comppow(z, 3), complex(1.0, 0.0));
		if (comp_abs(top) < 1e-6)
			break ;
		bot = real_mult(pow_two(z), 3);
		z = sub_comp(z, comp_div(top, bot));
		i++;
	}
	return (get_color(i));
}
