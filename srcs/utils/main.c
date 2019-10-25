#include "fractol.h"

static t_type	get_type_2(char *name);

static t_type	get_type(char *name)
{
	if (ft_strequ(name, "Mandelbrot"))
		return (MANDELBROT);
	else if (ft_strequ(name, "BurningShip"))
		return (BURN_SHIP);
	else if (ft_strequ(name, "Celtic"))
		return (CELTIC);
	else if (ft_strequ(name, "Spider"))
		return (SPIDER);
	else if (ft_strequ(name, "Julia"))
		return (JULIA);
	else if (ft_strequ(name, "Phoenix"))
		return (PHOENIX);
	else if (ft_strequ(name, "Manowar"))
		return (MANOWAR);
	else
		return (get_type_2(name));
}

static t_type	get_type_2(char *name)
{
	if (ft_strequ(name, "Newton"))
		return (NEWTON);
	else if (ft_strequ(name, "Nova"))
		return (NOVA);
	else if (ft_strequ(name, "Multibrot"))
		return (MULTIBROT);
	else if (ft_strequ(name, "Multijulia"))
		return (MULTIJULIA);
	return (INVALID);
}

static void		create_fractals(int ac, char **av)
{
	t_fract		*fracts[MAX_WINDOWS];
	void		*mlx;
	int			i;

	i = -1;
	if ((mlx = mlx_init()) == NULL)
		error_exit(MLX_INIT_ERR);
	while (++i < ac - 1)
	{
		fracts[i] = fract_init(av[i + 1], get_type(av[i + 1]), mlx);
		fill_image(fracts[i]);
	}
	mlx_loop(mlx);
	i = -1;
	while (++i < ac - 1)
		fract_clear(&fracts[i], 0);
	ft_memdel((void**)&mlx);
}

int				main(int ac, char **av)
{
	int			i;
	t_type		type;

	i = 0;
	if (ac < 2 || ac > 6)
	{
		ft_printf("Usage: ./fractol NAME");
		ft_printf("NAMES : Mandelbrot, BurningShip, Manowar, Spider, Multibrot, \n \
		Celtic, Julia, Phoenix, MultiJulia, Newton, Nova");
		return (0);
	}
	while (++i < ac - 1)
	{
		if ((type = get_type(av[i])) == INVALID)
			error_exit(INVALID_NAME);
	}
	create_fractals(ac, av);
	exit (0);
}
