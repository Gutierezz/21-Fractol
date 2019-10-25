/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 18:17:47 by ttroll            #+#    #+#             */
/*   Updated: 2019/10/25 18:21:11 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		fract_clear(t_fract **fract, int err_msg)
{
	if (*fract)
	{
		if ((*fract)->img)
			mlx_destroy_image((*fract)->mlx, (*fract)->img);
		if ((*fract)->win)
			mlx_destroy_window((*fract)->mlx, (*fract)->win);
		ft_memdel((void**)fract);
	}
	if (err_msg)
		error_exit(err_msg);
}

void		error_exit(int err)
{
	if (err == MLX_INIT_ERR)
		ft_fprintf(2, "Mlx initialization failed\n");
	if (err == WINDOW_INIT_ERR)
		ft_fprintf(2, "Mlx initialization failed\n");
	if (err == IMAGE_INIT_ERR)
		ft_fprintf(2, "Mlx initialization failed\n");
	if (err == DATA_ADDR_ERR)
		ft_fprintf(2, "Mlx initialization failed\n");
	if (err == MEM_ALLOC_ERR)
		ft_fprintf(2, "Mlx initialization failed\n");
	exit(err);
}
