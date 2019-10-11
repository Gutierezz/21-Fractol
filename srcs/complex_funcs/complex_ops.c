#include "fractol.h"

void		comp_print(t_complex c)
{
	ft_printf("re: %.10lf im: %.10lf \n", c.re, c.im);
}

t_complex	pow_two(t_complex c)
{
	t_complex	res;

	res.re = pow(c.re, 2.0) - pow(c.im, 2.0);
	res.im = 2 * c.re * c.im;
	return (res);
}

t_complex	comppow(t_complex c, int power)
{
	t_complex	res;
	int			i;

	i = -1;
	res = complex(1.0, 0.0);
	while (++i < power)
		res = comp_mult(res, c);
	return (res);
}

t_complex	real_mult(t_complex c, double num)
{
	t_complex	res;

	res.re = c.re * num;
	res.im = c.im * num;
	return (res);
}

t_complex	reverse_comp(t_complex c)
{
	t_complex res;

	res.re = (c.re / (pow(c.re, 2.0) + pow(c.im, 2.0)));
	res.im = -(c.im / (pow(c.re, 2.0) + pow(c.im, 2.0)));
	return (res);
}

double	comp_abs(t_complex c)
{
	return (sqrt(pow(c.re, 2.0) + pow(c.im, 2.0)));
}

int			in_circle(t_complex c)
{
	return (pow(c.re, 2.0) + pow(c.im, 2.0) <= 4.0);
}

// int			*get_coeff(int power)
// {
// 	static int	coeffs[10];
// 	int			tmp[10];
// 	int			i;
// 	int			j;

// 	i = 1;
// 	tmp[0] = 1;
// 	tmp[1] = 1;
// 	ft_bzero((void*)coeffs, sizeof(int) * 10);
// 	// ft_printf("start\n");
// 	// array_print(coeffs, 10);
// 	// array_print(tmp, 10);
// 	while (++i <= power)
// 	{
// 		j = 0;
// 		coeffs[0] = tmp[0];
// 		while (++j <= power)
// 			coeffs[j] = tmp[j - 1] + tmp[j];
// 		while (j--)
// 			tmp[j] = coeffs[j];
// 	}
// 	//ft_bzero((void*)tmp, sizeof(int) * 10);
// 	// array_print(coeffs, 10);
// 	// array_print(tmp, 10);
// 	return (coeffs);
// }

// t_complex	comppow(t_complex c, int power)
// {
// 	t_complex		res;
// 	int				*coeff;
// 	int				i;
// 	double			a_pow;
// 	double			b_pow;

// 	a_pow = (double)power;
// 	b_pow = (double)0;
// 	res = complex(0.0, 0.0);
// 	i = -1;
// 	if (power < 2 || power > 9)
// 		return (power == 1) ? c : complex(1, 0);
// 	coeff = get_coeff(power);
// 	while (++i <= power)
// 	{
// 		if ((i % 4) == 1)
// 			res.im += ((double)coeff[i] * pow(c.re, a_pow) * pow(c.im, b_pow));
// 		else if ((i % 4) == 2)
// 			res.re += -1.0 * (double)coeff[i] * pow(c.re, a_pow) * pow(c.im, b_pow);
// 		else if ((i % 4) == 3)
// 			res.im += -1.0 * (double)coeff[i] * pow(c.re, a_pow) * pow(c.im, b_pow);
// 		else if ((i % 4) == 0)
// 			res.re += (double)coeff[i] * pow(c.re, a_pow) * pow(c.im, b_pow);
// 		a_pow -= 1.0;
// 		b_pow += 1.0;
// 	}
// 	return (res);
// }


// void	array_print(int *arr, int n)
// {
// 	int i = -1;
// 	while (++i < n)
// 		ft_printf("%d ", arr[i]);
// 	ft_printf("\n");
// }
