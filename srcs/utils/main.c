#include "fractol.h"

static	t_type get_type_2(char *name);

static	t_type get_type(char *name)
{
	if (ft_strequ(name, "Mandelbrot"))
		return (MANDELBROT);
	else if (ft_strequ(name, "Mandelbar"))
		return (MANDELBAR);
	else if (ft_strequ(name, "Mandeldrop"))
		return (MANDELDROP);
	else if (ft_strequ(name, "BurningShip"))
		return (BURN_SHIP);
	else if (ft_strequ(name, "Buffalo"))
		return (BUFFALO);
	else if (ft_strequ(name, "Celtic"))
		return (CELTIC);
	else if (ft_strequ(name, "Spider"))
		return (SPIDER);
	else if (ft_strequ(name, "Julia"))
		return (JULIA);
	else
		return (get_type_2(name));
}

static	t_type get_type_2(char *name)
{
	if (ft_strequ(name, "Phoenix"))
		return (PHOENIX);
	else if (ft_strequ(name, "Manowar"))
		return (MANOWAR);
	else if (ft_strequ(name, "Newton"))
		return (NEWTON);
	else if (ft_strequ(name, "Nova"))
		return (NOVA);
	else if (ft_strequ(name, "Multibrot"))
		return (MULTIBROT);
	else if (ft_strequ(name, "Multijulia"))
		return (MULTIJULIA);
	return (INVALID);
}

int	main(int ac, char **av)
{
	t_fract	*fract;
	t_type	type;

	fract = NULL;
	if (ac < 2)
	{
		ft_printf("Usage: ./fractol NAME");
		ft_printf("NAMES : Mandelbrot, BurningShip, Mandelbar, Mandeldrop, Manowar,\n \
				Buffalo, Spider, Multibrot, Celtic, Julia,\n \
				Phoenix, BurningShipJulia, MultiJulia, Newton, Nova");
		return (0);
	}
	if ((type = get_type(av[1])) == INVALID)
		error_exit(INVALID_NAME);
	fract = fract_init(av[1], type);
	fill_image(fract);
	mlx_loop(fract->mlx);
	fract_clear(&fract, 0);
	return (0);
}
