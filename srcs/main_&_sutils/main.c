#include "fractol.h"

static	t_type get_type(char *name)
{
	if (ft_strequ(name, "Mandelbrot"))
		return (MANDELBROT);
	if (ft_strequ(name, "Julia"))
		return (JULIA);
	if (ft_strequ(name, "Burning Ship"))
		return (BURN_SHIP);
	if (ft_strequ(name, "Mandelbar"))
		return (MANDELBAR);
	if (ft_strequ(name, "Manowar"))
		return (MANOWAR);
	if (ft_strequ(name, "Phoenix"))
		return (PHOENIX);
	if (ft_strequ(name, "Mandeldrop"))
		return (MANDELDROP);
	if (ft_strequ(name, "test"))
		return (TEST);
	return (INVALID);
}

int	main(int ac, char **av)
{
	//comp_print(comp_div(complex(1.5, -1.0423), complex(2.612, 0.0072)));
	//exit(0);
	t_fract	*fract;
	t_type	type;

	fract = NULL;
	if (ac < 2)
	{
		ft_printf("Usage: ./fractol NAME (allowed names : Mandelbrot, Julia, Burning_Ship, Mandelbar)");
		return (0);
	}
	if ((type = get_type(av[1])) == INVALID)
		error_exit(INVALID_NAME);
	fract = fract_init(av[1], type);
	fill_image(fract);
	// double angle = 0;
	// int i = 0;
	// while(++i < 1000)
	// {
	// 	ft_printf("looped\n");
	// 	fract->julia_seed.re = sin(2 * angle);
	// 	fract->julia_seed.im = cos(angle / 2);
	// 	angle += 0.05;
	// 	fill_image(fract);
	// 	sleep(2);
	// };
	mlx_loop(fract->mlx);
	fract_clear(&fract, 0);
	return (0);
}
