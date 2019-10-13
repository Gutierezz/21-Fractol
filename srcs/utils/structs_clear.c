#include "fractol.h"

void	fract_clear(t_fract **fract, int err_msg)
{
	ft_printf("Fract_CLEAR!\n");
	if (*fract)
	{
		if ((*fract)->img)
			mlx_destroy_image((*fract)->mlx, (*fract)->img);
		if ((*fract)->win)
			mlx_destroy_window((*fract)->mlx, (*fract)->win);
		//ft_memdel((void**)&(*fdf)->data);
		//ft_memdel((void**)&(*fdf)->img);
		ft_memdel((void**)&(*fract)->mlx);
		ft_memdel((void**)fract);
	}
	if (err_msg)
		error_exit(err_msg);
}

void		error_exit(int err)
{
	ft_fprintf(2, "Error : %d\n", err);
	exit (err);
}
