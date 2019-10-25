/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_arithmetics.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 18:24:50 by ttroll            #+#    #+#             */
/*   Updated: 2019/10/25 18:27:58 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex		comp_mult(t_complex c1, t_complex c2)
{
	t_complex	res;

	res.re = c1.re * c2.re - c1.im * c2.im;
	res.im = c2.re * c1.im + c1.re * c2.im;
	return (res);
}

t_complex		comp_div(t_complex c1, t_complex c2)
{
	t_complex	res;

	res.re = ((c1.re * c2.re + c1.im * c2.im) / \
	(pow(c2.re, 2.0) + pow(c2.im, 2.0)));
	res.im = ((c2.re * c1.im - c1.re * c2.im) / \
	(pow(c2.re, 2.0) + pow(c2.im, 2.0)));
	return (res);
}

t_complex		add_comp(t_complex c1, t_complex c2)
{
	t_complex	res;

	res.re = c1.re + c2.re;
	res.im = c1.im + c2.im;
	return (res);
}

t_complex		sub_comp(t_complex c1, t_complex c2)
{
	t_complex	res;

	res.re = c1.re - c2.re;
	res.im = c1.im - c2.im;
	return (res);
}

t_complex		real_mult(t_complex c, double num)
{
	t_complex	res;

	res.re = c.re * num;
	res.im = c.im * num;
	return (res);
}
