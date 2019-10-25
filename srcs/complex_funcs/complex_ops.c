/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 18:24:56 by ttroll            #+#    #+#             */
/*   Updated: 2019/10/25 18:28:26 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			comp_print(t_complex c)
{
	ft_printf("re: %.10lf im: %.10lf \n", c.re, c.im);
}

t_complex		pow_two(t_complex c)
{
	t_complex	res;

	res.re = pow(c.re, 2.0) - pow(c.im, 2.0);
	res.im = 2 * c.re * c.im;
	return (res);
}

t_complex		comppow(t_complex c, int power)
{
	t_complex	res;
	int			i;

	i = -1;
	res = complex(1.0, 0.0);
	while (++i < power)
		res = comp_mult(res, c);
	return (res);
}

t_complex		reverse_comp(t_complex c)
{
	t_complex	res;

	res.re = (c.re / (pow(c.re, 2.0) + pow(c.im, 2.0)));
	res.im = -(c.im / (pow(c.re, 2.0) + pow(c.im, 2.0)));
	return (res);
}

double			comp_abs(t_complex c)
{
	return (sqrt(pow(c.re, 2.0) + pow(c.im, 2.0)));
}
